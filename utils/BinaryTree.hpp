#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>
#include "pair.hpp"

namespace ft
{
	namespace
	{
		/* --- Some forward declarations for non-member method 'isLeaf' --- */
		template <class Key, class T, class Compare, class Alloc>
		class Node;

		template <class Key, class T, class Compare, class Alloc>
		bool isLeaf(Node<Key, T, Compare, Alloc> *node);
		/* --- -------------------------------------------------------- --- */

		template <class Key, class T, class Compare, class Alloc>
		class Node
		{
		public:
			typedef				Key											key_type;
			typedef				T											mapped_type;
			typedef				Compare										key_compare;
			typedef typename	ft::pair<const key_type, mapped_type>		value_type;
			typedef typename	Alloc::template rebind<Node<key_type,					//rebind permet de definir le type que l on veut allouer 
								mapped_type, key_compare, Alloc> >::other	allocator_type;
			typedef typename	ft::pair<key_compare, allocator_type>		map_traits_type;

			// Constructor & Destructors
			Node(const map_traits_type& map_traits, const value_type& pair)
			: left(NULL), right(NULL), parent(NULL), end(false), pair(pair),
			  compare(map_traits.first), alloc(map_traits.second) {}

			Node(Node *parent, const map_traits_type& map_traits, const value_type& pair)
			: left(NULL), right(NULL), parent(parent), end(false), pair(pair),
			  compare(map_traits.first), alloc(map_traits.second) {}

			//Constructeur pour node de fin, pas besoin d allocator ou de compare car n alloue rien
			Node() : left(NULL), right(NULL), parent(NULL), end(true),
					 pair(value_type()), compare(Compare()), alloc(allocator_type())
			{}

			Node(const Node &other) : left(NULL), right(NULL),
				parent(other.parent), end(other.end), pair(other.pair),
				compare(other.compare), alloc(other.alloc) {}

			// Copie des descendants maitrisees
			void copyDescendants(const Node* other) {
				if (!isLeaf(other->left)) {
					this->createChild(other->left->pair, true);
					this->left->copyDescendants(other->left);
				}
				if (!isLeaf(other->right)) {
					this->createChild(other->right->pair, false);
					this->right->copyDescendants(other->right);
				}
			}

			// Detruit tout l'arbre, car le gauche fait appel 
			// a son destructeur qui fait ensuite apel a celui ci et ainsi de suite
			~Node() {
				this->deallocate(this->left);
				this->deallocate(this->right);
			}

			// Operators
			bool operator==(const Node& other) const { return this->pair == other.pair; }
			bool operator==(const value_type& pair) const { return this->pair == pair; }
			bool operator==(const key_type& key) const { return this->pair.first == key; }
			bool operator!=(const Node& other) const { return !(*this == other); }
			bool operator!=(const value_type& pair) const { return  !(*this == pair); }
			bool operator!=(const key_type& key) const { return !(*this == key); }

			value_type operator*() const {
				return this->pair;
			}
			value_type *operator->() {
				return &this->pair;
			}
			value_type &operator*() {		// lvalue
				return this->pair;
			}

			/* Methods */
			
			// Sorte de find pour trouver une key selon si elle est inferieure ou
			// superieure a la key de notre paire
			Node* next(const key_type& key) const {
				return this->compare(key, this->pair.first) ? this->left : this->right;
			}
			// Permet d'avoir la node suivante, la plus petite node superieure a la notre
			// Si il y a un child right, on fait droite pour  y acceder 
			// puis tous ses enfants a gauche
			// Sinon on remonte jusqu a trouver un plus grand que lui meme

			Node* next() const {
				Node *p;
				if (this->right) {//child right
					p = this->right;
					if (!p->end)
						while (!isLeaf(p->left))
							p = p->left;
				} else {
					p = this->parent;
					while (p && this->parent->pair.first < this->pair.first)
						p = p->parent;
				}
				return p;
			}


			// Permet d'ajouter une node a la suite de notre node courante
			// Si la cle existe deja la valeur est modifie mais aucune node n'est ajoutee
			Node* add(const value_type& pair) {
				if (this->pair.first == pair.first) {
					this->pair.second = pair.second;
					return this;
				}
				bool left = this->compare(pair.first, this->pair.first);
				Node *child = left ? this->left : this->right;
				if (!child || (child && child->end)) {
					this->createChild(pair, left);
					return left ? this->left : this->right;
				}
				else
					return child->add(pair);// recursive : permet d'aller jusqu a une node qui n a pas d'enfant la ou ca doit etre mis
			}

			Node* erase() {
				Node *p = this->left ? this->left : this->right, *ret;
				if (this->relinkToChild(p, NULL))								// No children
					return NULL;
				if ((ret = this->relinkToChild(p, &this->right)))				// Only right
					return ret;
				while (p->right) // Si il y a au moins 1 left, on descend tout a droite du gauche
					p = p->right;
				if ((ret = this->relinkToChild(p, &this->left, !this->right)))	// Only left
					return ret;
				Node *newRoot = p;	// Cas ou on doit supprimer la root	
				while (newRoot->parent) // Cas ou il y a deux enfants 
					newRoot = newRoot->parent;
				this->pair = p->pair;											// Both : pas besoin de relink juste mettre a la place
				this->changeParentPOV(p, p->left ? &p->left : NULL); // definit le nouvel enfant du parent 
				this->deallocate(p);
				return newRoot; // newroot = root
			}

			Node *first() { // begin
				Node* p = this;
				while (p->parent)
					p = p->parent;
				while (!isLeaf(p->left))
					p = p->left;
				return p;
			}
			Node *last() { // end - 1
				Node* p = this;
				while (p->parent)
					p = p->parent;
				while (!isLeaf(p->right))
					p = p->right;
				return p;
			}

			// droite de end = premier et gauche de end = dernier
			// a droite du dernier = end et a gauche du premier = end
			void updateEnd(Node *end, bool checkFirst = true, bool checkLast = true) {
				if (!checkLast || this->pair.first > end->left->pair.first) { //dernier
					this->right = end;
					end->left = this;
				}
				if (!checkFirst || this->pair.first < end->right->pair.first) { //premier
					this->left = end;
					end->right = this;
				}
			}

			// Specific function for end node
			// Evite de segfault car permet de delier le end de notre arbre car sinon
			// il aurait boucler a l'infini en tentant de redetruire des child deja detruits
			void unlink() {
				if (this->left)
					this->left->right = NULL;
				if (this->right)
					this->right->left = NULL;
				this->right = NULL;
				this->left = NULL;
			}

			// Permet de savoir si la node est une feuille 
			//(feuille soit NULL soit end (au bout de l'arbre))
			friend bool isLeaf<Key, T, Compare, Alloc>(Node *node);

		private:
			/* Links to the tree */
			Node			*left;	//child left
			Node			*right;	//child right 
			Node			*parent;
			bool			end; // true if is end node else false

			/* Data */
			value_type		pair;

			/* Map variables */
			key_compare		compare;
			allocator_type	alloc;

			/* Utils */

			// Chaque node a deux childs possible max
			// si booleen true > creer enfant a gauche sinon a droite
			// this = le parent
			void createChild(const value_type& pair, bool left) {
				Node **child = left ? &this->left : &this->right;
				*child = this->alloc.allocate(1);
				this->alloc.construct(*child,
					Node(this, ft::make_pair(this->compare, this->alloc), pair));
			}

			void deallocate(Node *p) {
				if (p)
					this->alloc.destroy(p);
				this->alloc.deallocate(p, 1);
			}

			// Node supprime, p est remplace par un autre enfant newPOV du point de vue des parents
			void changeParentPOV(Node *p, Node **newPOV) {
				if (!p->parent)
					return ;
				bool pIsLeftChild = (p == p->parent->left);
				Node **pFromParentPOV = pIsLeftChild ? &p->parent->left : &p->parent->right;
				*pFromParentPOV = newPOV ? *newPOV : NULL;
				if (newPOV)
					(*newPOV)->parent = p->parent;
				p->left = NULL;
				p->right = NULL;
			}

			// Si p = child alors on relink sinon non
			// p->parent c est nous et si p->parent->parent est NULL 
			// on a pas de parent on est donc une root
			Node* relinkToChild(Node *p, Node **child, bool additionalCond = true) {
				if (p == (child ? *child : NULL) && additionalCond) {
					if (p && !p->parent->parent) { // if we're erasing the root and it has one and only one child
						*child = NULL; // Dans ce cas(soit 0 ou 1 seul enfant) pas de relinkage, root supprime
						this->deallocate(p->parent);
						p->parent = NULL;
					} else { //change le pov du parent(nous) par l'enfant
						this->changeParentPOV(this, child);
						this->deallocate(this);
					}
					if (!p)
						return this;//renvoie root
					while (p->parent)
						p = p->parent; //sinon remonte jusqu au parent et c est la root
					return p;
				}
				return NULL;
			}

			// Should never be used
			Node& operator=(const Node& other);
		};

		template <class Key, class T, class Compare, class Alloc>
		bool isLeaf(Node<Key, T, Compare, Alloc> *node) {
			return !node || node->end;
		}
	}

	template <class Key, class T, class Compare, class Alloc>
	class BinaryTree
	{
	public:
		typedef 			Key												key_type;
		typedef 			T												mapped_type;
		typedef typename	ft::pair<const key_type, mapped_type>			value_type;
		typedef				Compare											key_compare;
		typedef 			Node<key_type, mapped_type, key_compare, Alloc>	node_type;
		typedef typename	Alloc::template rebind<node_type>::other		allocator_type;
		typedef typename	ft::pair<key_compare, allocator_type>			map_traits_type;
		typedef 			size_t											size_type;

		// Constructors & Destructors
		BinaryTree(const typename ft::pair<key_compare, Alloc>& map_traits)
		: root(NULL), end_ptr(&endd), sizee(0), map_traits(map_traits) {}
		BinaryTree(const BinaryTree& other)
		: root(NULL), end_ptr(&endd), sizee(0), map_traits(other.map_traits) {
			*this = other;
		}

		// deep copy
		BinaryTree& operator=(const BinaryTree& other) {
			// Copying all nodes (by reallocation)
			if (other.root) { // si il a une root
				if (this->root) // on detruit la notre
					this->deleteRoot(); 
				this->createRoot(**other.root); // on creer une copie de la sienne
				this->root->copyDescendants(other.root); // on reconstruit notre arbre
			}
			// Initializing end node
			node_type *begin = this->begin();
			node_type *last = this->root->last();
			last->updateEnd(&this->endd, true, false);
			begin->updateEnd(&this->endd, false, true);
			// Other attributes
			this->sizee = other.sizee;
			this->map_traits.first = other.map_traits.first;
			return *this;
		}
		~BinaryTree() {
			this->deleteRoot(); // detruit la root et tout le reste en cascade
		}

		// Methods
		node_type* insert(const value_type& pair) {
			this->sizee++;
			if (!this->root) {
				this->createRoot(pair);
				return this->root;
			}
			else {
				node_type *p = this->root->add(pair);
				p->updateEnd(&this->endd);
				return p;
			}
		}

		bool erase(const key_type& key) {
			node_type *p = this->find(key); //Existe t'elle?
			if (!p)
				return false;
			node_type *newRoot = p->erase(); 
			this->root = newRoot ? newRoot : this->root;
			if (--this->sizee == 0)
				this->root = NULL;
			return true;
		}

		node_type *find(const key_type& key) const {
			node_type *ret = this->root;
			while (!isLeaf(ret) && *ret != key)
				ret = ret->next(key);
			return isLeaf(ret) ? NULL : ret;//si c est une feuille return NULL sinon ret
		}

		node_type *begin() const { // la node la plus petite
			if (!this->root)
				return NULL;
			return this->root->first();
		}

		node_type *end() const { // la end node 
			return this->end_ptr;
		}

		size_type size() const {
			return this->sizee;
		}

	private:
		node_type*	root;
		node_type		endd;
		node_type		*end_ptr; // for const
		size_type		sizee;
		map_traits_type	map_traits;

		// Allocation Manager
		void createRoot(const value_type& pair) {
			this->root = this->map_traits.second.allocate(1);
			this->map_traits.second.construct(this->root, node_type(this->map_traits, pair));
			this->root->updateEnd(&this->endd, false, false);
		}
		void deleteRoot() {
			this->endd.unlink();
			if (this->root)
				this->map_traits.second.destroy(this->root);
			this->map_traits.second.deallocate(this->root, 1);
		}
	};
}
#endif // BINARYTREE_HPP
