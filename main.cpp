#include <iostream>

#ifdef MINE
	#include "vector/vector.hpp"
	#include "stack/stack.hpp"
#else
	#include <vector>
	#include <stack>
#endif

using namespace NAMESPACE;

#define CYAN "\033[0;36m"
#define END_COLOR "\033[0m"


int main()
{
	/////////////////////// TEST Vector ////////////////////

	std::cout << std::endl <<  CYAN <<  "************* Test Vector *************" << END_COLOR << std::endl << std::endl;

	vector<int> v(3, 42);

	std::cout << "v: ";
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	if (v.empty())
		std::cout << "hey" << std::endl;

	std::cout << "v.front() and v.back(): ";
	std::cout << v.front() << " " << v.back() << std::endl;
	
	std::cout << "v.size(): ";
	if (!v.empty())
		std::cout << v.size() << std::endl;
	
	vector<int> v2(2, 5);
	v = v2;
	std::cout << "v2: ";
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	std::cout << "v: ";
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	
	vector<int> v3(v);	
	std::cout << "v3 (copy of v): ";
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl << "v3[1]: " << v3[1] << std::endl;
	std::cout << v3.at(1) << std::endl;
	try {
		v3.at(2);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	vector<int> v4;
	if (v4.empty())
		std::cout << "Default Constructor is empty " << std::endl;

	const vector<int> vc(v3);
	std::cout << *vc.begin() << std::endl;
	vector<int>::const_iterator last = vc.end() - 1;
	std::cout << *last << std::endl;
	std::cout << vc.front() << " " << vc.back() << std::endl;
	std::cout << vc[1] << std::endl;
	std::cout << vc.at(1) << std::endl;
	try {
		vc.at(-3);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	/*vector<float> v5(v3.begin(), v3.end());
	std::cout << "v5 Range constructor: ";
	for (vector<float>::iterator it = v5.begin(); it != v5.end(); it++)
	std::cout << *it << " ";
	std::cout << std::endl;*/

	////////////////////// TEST REVERSE_ITERATOR ////////////////////////
	
	std::cout << std::endl << CYAN << "********** Test Reverse Iterator **********" << END_COLOR << std::endl << std::endl;

	std::cout << "Test 1: ";
	vector<int> vec(5, 7);
/*	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
    for(reverse_iterator<vector<int>::iterator> it = vec.rbegin(); it != vec.rend(); it++)
	        std::cout << *it << " ";
	std::cout << std::endl;
*/	
	std::cout << "Test 2: ";
//	vector<int>::iterator from(vec.begin());
//	vector<int>::iterator until(vec.end());
	reverse_iterator<vector<int>::iterator> rev_until(vec.begin());
	reverse_iterator<vector<int>::iterator> rev_from(vec.end());
//	while (rev_from != rev_until)
//		std::cout << *rev_from++ << " ";
	std::cout << std::endl;

	////////////////////// TEST STACK //////////////////////////////

/*	std::cout << std::endl << CYAN << "************ Test Stack ************" << END_COLOR << std::endl << std::endl;

		
	std::cout << "  * Constructor of stack Test : *  " << std::endl;
	std::deque<int> mydeque(3, 10);
	stack<int> first; 				    // empty stack
	std::cout << "size of empty stack: " << first.size() << std::endl;
	stack<int> second (mydeque);		// stack initialized to copy of deque
	std::cout << "size of stack copy of deque: " << second.size() << std::endl;
*//*
	stack<int> c1;
	c1.push(5);
	std::cout << "Stack c1 size: " << c1.size() << std::endl;
	stack<int> c2(c1);
	std::cout << "Copy stack c1 in c2 size: " << c2.size() << std::endl;
	c2.push(6);
	c2.push(3);
	c2.push(2);
	std::cout << "Stack c2 size after push: " << c2.size() << std::endl;
*/
	return 0;
}
