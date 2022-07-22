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
### Map :
### Others :

///////////


##### Ex00 : Megaphone
![megaphone](./img/day00Ex00.png)  

