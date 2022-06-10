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
	/////////////////////// TEST Vector ////////////////////

	std::cout << std::endl <<  CYAN <<  "************* Test Vector *************" << END_COLOR << std::endl << std::endl;

	vector<int> v(3, 42);

	std::cout << YELLOW << "Test 1: Basic functions empty(), front(), back(), size()" << END_COLOR << std::endl;
	std::cout << "v: ";
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	if (v.empty())
		std::cout << "V is empty" << std::endl;

	std::cout << "v.front() and v.back(): ";
	std::cout << v.front() << " " << v.back() << std::endl;
	
	std::cout << "v.size(): ";
	if (!v.empty())
		std::cout << v.size() << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Test 2: boucle from begin() to end()" << END_COLOR << std::endl;
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
	std::cout << std::endl;
	
	std::cout << YELLOW << "Test 3: Copy Constructor" << END_COLOR << std::endl;
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
	std::cout << std::endl;
 
	std::cout << YELLOW << "Test 4: Default constructor" << END_COLOR << std::endl;
	vector<int> v4;
	if (v4.empty())
		std::cout << GREEN << "Default Constructor is empty " << END_COLOR << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "Test 5: " << END_COLOR << std::endl;
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

	std::cout << std::endl;
	std::cout << YELLOW << "Test 5: iterator incrementation & decrementation" << END_COLOR << std::endl;
	v3.push_back(10);
	v3.push_back(11);
	v3.push_back(12);
	v3.push_back(13);
	v3.push_back(14);
    for(vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	        std::cout << *it << " ";
	vector<int>::iterator it3(v3.begin());
	std::cout << "test -= and += with iterator" << std::endl;
	it3 += 2;
	std::cout << "Increment it += 2: "<< *it3 << std::endl;
	std::cout << "Increment it += 2: "<< *(it3 += 2) << std::endl;
	it3 -= 2;
	std::cout << "Decrement it-=2: " << *it3 << std::endl;
	std::cout << "Decrement it-=2: " << *(it3 -= 2) << std::endl;
	
	std::cout << std::endl;
	vector<int>::const_iterator it4(v3.begin());
	std::cout << "test -= and += with const iterator" << std::endl;
	it4 += 2;
	std::cout << "Increment it += 2: "<< *it4 << std::endl;
	std::cout << "Increment it += 2: "<< *(it4 += 2) << std::endl;
	it4 -= 2;
	std::cout << "Decrement it-=2: " << *it4 << std::endl;
	std::cout << "Decrement it-=2: " << *(it4 -= 2) << std::endl;
	std::cout << std::endl;

	/*vector<float> v5(v3.begin(), v3.end());
	std::cout << "v5 Range constructor: ";
	for (vector<float>::iterator it = v5.begin(); it != v5.end(); it++)
	std::cout << *it << " ";
	std::cout << std::endl;*/
	return 0;
}
