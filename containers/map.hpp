#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <functional>
# include <stdexcept>
# include "../utils/iterator_traits.hpp"
# include "../utils/pair.hpp"
# include "../iterators/map_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../utils/BinaryTree.hpp"

namespace ft
{
	template <	class Key, class T,
				class Compare = std::less<Key>, 
				class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	private:
		typedef typename	ft::BinaryTree<Key, T, Compare, Alloc>			bt_type;
		typedef typename	bt_type::node_type								node_type;
	public:
		typedef				Key												key_type;
		typedef				T												mapped_type;
		typedef typename	ft::pair<const key_type, mapped_type>			value_type;
		typedef				Compare											key_compare;
		//typedef 															value_compare;
		typedef				Alloc											allocator_type;
		typedef typename	allocator_type::reference						reference;
		typedef typename	allocator_type::const_reference					const_reference;
		typedef typename	allocator_type::pointer							pointer;
		typedef typename	allocator_type::const_pointer					const_pointer;
		typedef				map_iterator<value_type, node_type>				iterator;
		typedef				map_iterator<const value_type, node_type>		const_iterator;
		typedef typename	ft::reverse_iterator<iterator>					reverse_iterator;
		typedef typename	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef typename	ft::iterator_traits<iterator>::difference_type	difference_type;
		typedef				size_t											size_type;

		// Constructors & Destructor
		explicit map(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
		: bt(ft::make_pair(comp, alloc)) {} // creer le binary tree

		// Creer binary tree et le remplit de first a last
		template <class InputIterator>
		map(InputIterator first, InputIterator last,
			const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type())
		: bt(ft::make_pair(comp, alloc)) {
			for (InputIterator it = first; it != last; it++)
				bt.insert(*it);
		}

		map(const map& x) : bt(x.bt) {
			*this = x;
		}

		map& operator=(const map& x) {
			this->bt = x.bt;
			return *this;
		}

		~map() {}

		// Iterators
		iterator begin() {
			return iterator(this->bt.begin());
		}
		const_iterator begin() const {
			const_iterator ret(this->bt.begin());
			return ret;
		}
		iterator end() {
			return iterator(this->bt.end());
		}
		const_iterator end() const {
			const_iterator ret(this->bt.end());
			return ret;
		}

		// Capacity
		bool empty() const {
			return (this->bt.size() == 0);
		}
		size_type size() const {
			return this->bt.size();
		}
		size_type max_size() const {
			return this->alloc.max_size();
		}

		/* Element access */
		// Operateur[] : peut modifier, lire, inserer 
		// ex: map['p']; is value_initialized car key n'ayant pas de valeur
		// 	   map['p'] = 42; insere 42 et si 'p' existe deja la valeur est juste modifie
		mapped_type& operator[](const key_type& k) {
			node_type *p = this->bt.find(k);
			if (!p)
				p = this->bt.insert(ft::make_pair(k, mapped_type()));
			// p forcement initialise a ce moment la soit par la nouvelle
			// valeur insere soit parce qu on l a trouve
			value_type& val = **p; // **p = value_type = paire
			return val.second;// second = valeur. dans l exemple c est 42
		}

		// Comme operateur[] sauf que si on trouve pas la cle on renvoie une exception
		// On peut que modifier ou lire une cle existante pas en inserer
		mapped_type& at(const key_type& k) {
			node_type *p = this->bt.find(k);
			if (!p)
				throw std::out_of_range("map::at");
			value_type& val = **p;
			return val.second;
		}

		// const donc peut que lire
		const mapped_type& at(const key_type& k) const {
			node_type *p = this->bt.find(k);
			if (!p)
				throw std::out_of_range("map::at");
			value_type& val = **p;
			return val.second;
		}

	private:
		bt_type bt;
	};
}

#endif // MAP_HPP
