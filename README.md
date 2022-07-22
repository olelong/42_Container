# 42_container

C++ language
A Stack, map and vector reimplementation project.

### How to make the exercises work : 
``` git clone "my_repo_git" ```
``` cd my_repo_git ```
Run the ``` make ``` command to run only my ft_container.
Then launch the executable ``` ./executable_name ```.  
##### OR
Run the ``` make real ``` command to run only the stl container.
Then launch the executable ``` ./executable_name ```.  
##### OR
Run the ``` make test ``` command to run both and see the difference beteween them.

-> You can test differents mains, you just need to change PATH in the makefile:

``` SRCS_DIR	= mains/mine/ ```
``` SRCS		= main_map.cpp ```

### Stack :

Implement a Stack class taking in parameter of its template our Vector class by default.

#### The specificities of this container :
  - It works like a stack of plates where you can only remove the one on top.
    To access the elements of the stack, you must always access them from the last one.
  - It cannot be iterated.

#### Its functions :

empty():	Boolean, returns if the stack is empty (if its size is null).

size():		Returns the number of elements in the stack.

top():		Returns a reference to the top element of the stack. The element
		top is the last element inserted in the stack.
      
push(): 	Inserts a new element at the top of the stack, on top of its current
		top element. The content of this new element is a
		copy of val.
      
pop():  	Deletes the top element, reducing its size by 1.


#### Example of using Stack :

```
	stack<float> lhs; // Create a stack
	lhs.push(12); // Add an element to the stack
	lhs.pop(); // Delete the last added element
	
	std::cout << "size of lhs: " << lhs.size() << std::endl; // We display the size of our stack
	for (int i = 0; i < 5; i++) // We add to the stack n elements (here 5)
	{
		mystack.push(i); // We add i
		// We display i and we display the last element with top() to check that it is the same one:
		std::cout << "i: " << i << std::endl;
		std::cout << "top(): " << mystack.top() << std::endl;
	}
```

### Vector:

Vector is a kind of dynamic array that can change its size.

#### The specificities of this container :

	- It can change size dynamically.
	- It uses a dynamic allocation to store its elements, that is to say that it has a defined capacity
	  and that it doesn't reallocate at each insertion of a new element but rather when this capacity is exceeded.
	- Can be iterated with iterator and reverse_iterator.

#### Its main functions:

##### Iterators :

Begin():	Return an iterator on the beginning of the vector.

Rbegin():	Returns an iterator on the inverse of the beginning of the vector.

End():		Returns an iterator on the end of the vector.

Rend():		Returns an iterator on the inverse of the end of the vector.


##### Capacity :

size(), resize(), capacity() : Allow to manage and know the capacity or the size.

##### Element access :

operator[], at(), front(), back(): These are functions that allow to access elements of the array.

##### Modifiers :

assign(), push_back(), pop_back(), insert(), erase(), swap(), clear(): Allow to manage the elements of the array.

They will either add/insert one or more elements or delete, swap some...


#### Example of using Vector :

```
	vector<std::string> vect(1, "ok"); // We create a vector vect which will contain std::string
	vect.push_back("a"); // Add elements to it
	vect.push_back("b");
	vect.push_back("c");

	std::cout << vect.size(); // We display the size of the vector 
	std::cout << vect.capacity(); // Display its capacity
	
	vect.assign(5, 12); // We assign to our vector 5 times the value 12
	// We display the content of our vector:
	for (vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	
	vector<int>::iterator itie; // We create a vector iterator
	itie = vect.begin(); // We put our new iterator at the position of the vector begin
	vect.erase(itie + 1); // We erase in our vector the element at the position begin + 1

```













<p align="left"> ******************** FRENCH ********************** </p>

Le but du projet est d'implementer les containers Stack, map and vector.

### Comment lancer le programme :

``` git clone "my_repo_git" ```
``` cd my_repo_git ```

Tape la commande ``` make ``` pour lancer seulement mon ft_container.

Ensuite lance l'executable ``` ./executable_name ```.

##### OU
Tape la commande ``` make real ``` pour lancer le container de la stl.

Ensuite lance l'executable ``` ./executable_name ```.  

##### OU
Tape la commande ``` make test ``` pour compiler les deux containers et faire un make diff des deux.

-> Tu peux tester differents mains, en changeant le PATH dans le makefile:

``` SRCS_DIR	= mains/mine/ ```
``` SRCS		= main_map.cpp ```


### Stack :

Implementer une classe Stack prenant en parametre de son template notre classe Vector par defaut.

#### Les specificites de ce container :
  - Elle fonctionne comme une pile d'assiette ou on ne peut retirer que celle qui est pose sur le dessus.
    Pour acceder aux elements de la pile, il faut toujours y acceder depuis le dernier.
  - Elle ne peut pas etre iterer.

#### Ses fonctions :

empty():	Booleen, retourne si la pile est vide(si sa taille est nulle).

size():		Renvoie le nombre d'elements dans la pile.

top():		Renvoie une reference a l'element sommet de la pile. L'element
		sommet est le dernier element insere dans la pile.
      
push(): 	Insere un nouvel element en sommet de la pile, au dessus de son
		element sommet actuel. Le contenu de ce nouvel element est une
		copie de val.
      
pop():  	Supprime l'element sommet, reduisant ainsi sa taille de 1.

#### Exemple d'utilisation de Stack :
```
	stack<float> lhs; 	// On cree une stack
	lhs.push(12); 		// On ajoute a la stack un element
	lhs.pop(); 		// On supprime le dernier element ajoute
	
	std::cout << "size of lhs: " << lhs.size() << std::endl; // On affiche la taille de notre stack
	for (int i = 0; i < 5; i++) // On ajoute a la stack n elements (ici 5)
	{
		mystack.push(i); // On ajoute i
		// On affiche i et on affiche le dernier element avec top() pour verifier que c'est bien le meme:
		std::cout << "i: " << i  << std::endl;
		std::cout << "top(): " << mystack.top() << std::endl;
	}
```

### Vector :

Vector est une sorte de tableau dynamique qui peut changer de taille.

#### Les specificites de ce container :

	- Il peut changer de taille de façon dynamique.
	- Il utilise une allocation dynamique pour stocker ses elements, c'est a dire qu'il a une capacite definie
	et qu'il ne realloue pas a chaque insertion d'un nouvel element mais plutot lorsque cette capacite est depasse.
	- Peut etre itere avec iterator et reverse_iterator.

#### Ses fonctions principales :

##### Iterateurs :

Begin():	Retourne un iterateur sur le debut du vector.

Rbegin():	Retourne un iterateur sur l'inverse du debut du vector.

End():		Retourne un iterateur sur la fin du vector.

Rend():		Retourne un iterateur sur l'inverse de la fin du vector.


##### Capacity :

size(), resize(), capacity() : Permettent de gerer et connaitre la capacite ou la size.

##### Element access :

operateur[], at(), front(), back() : Ce sont des fonctions qui permettent d'acceder a des elements du tableau.

##### Modifiers :

assign(), push_back(), pop_back(), insert(), erase(), swap(), clear() : Permettent de gerer les elements du tableau.

Ils vont soit ajouter/inserer un ou des element.s ou en supprimer, en echanger...


#### Exemple d'utilisation de Vector :

```
	vector<std::string> vect(1, "ok"); 	// On cree un vector vect qui contiendra des std::string
	vect.push_back("a");			// On lui ajoute des elements
	vect.push_back("b");
	vect.push_back("c");

	std::cout << vect.size();		// On affiche la taille du vecteur 
	std::cout << vect.capacity();		// On affiche sa capacite
	
	vect.assign(5, 12);			// On assigne a notre vector 5 fois la valeur 12
	// On affiche le contenu de notre vector:
	for (vector<int>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	
	vector<int>::iterator itie;		// On creer un vector iterateur
	itie = vect.begin();			// On met notre nouvel iterateur a la position du begin du vector
	vect.erase(itie + 1);			// On erase dans notre vector l'element a la position begin + 1

```

### Map :
### Others :

-> iterator_traits est un moyen de recuperer les informations
d'un iterator.

-> enable_if permet d'autoriser ou interdire certains overloads (de types) (conditionnels) a la compilation.

C'est une metafonction*, en effet le resultat de cette fonction est obtenu et interprete a

la compilation (et non a l'execution).

*une metafonction est une struct.

-> is_integral teste si la class passee en parametre est un entier (son attribut value est set a true).

-> equal teste si une range (de first1 a last1) est egale a une autre range (a partir de first2).

-> lexicographical_compare compare range1 et range2, si range2 est plus petite ou si le premier element n'est 

pas egal a range1 et qu'il est plus petit, c'est false et vice-versa.

-> pair et make_pair fonctionnent avec map. Ils permettent de gerer et creer des paires.

///////////


##### Ex00 : Megaphone
![megaphone](./img/day00Ex00.png)  

