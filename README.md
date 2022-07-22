# 42_container

C++ language
A Stack, map and vector reimplementation project.

### How to make the exercises work: 
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


#### Example of using Stack:

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








<p align="left"> ******************** FRENCH ********************** </p>

Le but du projet est d'implementer les containers Stack, map and vector.

### Comment lancer le programme:

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
	- Il 

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

