#include <iostream>
#include <unistd.h>

#ifdef MINE
	#include "../../vector/vector.hpp"
	#include "../../stack/stack.hpp"
#else
	#include <vector>
	#include <stack>
#endif

using namespace NAMESPACE;

#define CYAN "\033[0;36m"
#define END_COLOR "\033[0m"
#define MAGENTA "\033[0;35m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"


int main()
{
	////////////////////// TEST STACK //////////////////////////////

	std::cout << std::endl << CYAN << "************ Test Stack ************" << END_COLOR << std::endl << std::endl;

		
	std::cout << YELLOW << "  * Constructor of stack Test : *  " << END_COLOR << std::endl;
	vector<int> myvec(3, 10);
	stack<int> first; 				    // empty stack
	std::cout << "size of empty stack: " << first.size() << std::endl;
	if (first.empty())
		std::cout << "test empty(), first is empty" << std::endl << std::endl;
	
	stack<int, vector<int> > second (myvec);		// stack initialized to copy of deque
	std::cout << "size of stack copy of vector: " << second.size() << std::endl;
	if (!second.empty())
		std::cout << "test empty(), second is not empty" << std::endl << std::endl;
	//std::cout << " test top(): " << second.top() << std::endl;	

	stack<int> c1;
//	c1.push(5);
	std::cout << "Stack c1 size: " << c1.size() << std::endl;
	stack<int> c2(c1);
	std::cout << "Copy stack c1 in c2 size: " << c2.size() << std::endl;
//	c2.push(6);
//	c2.push(3);
//	c2.push(2);
	std::cout << "Stack c2 size after push: " << c2.size() << std::endl;

	return 0;
}
