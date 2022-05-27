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

	std::cout << "Test 1: An empty constructor" << std::endl;
//	reverse_iterator<vector<int>::iterator> empty;

	std::cout << "Test 2:";
	vector<int> vec(5, 7);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	std::cout << std::endl;
	std::cout << "Iterator vec : ";
    for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	        std::cout << *it << " ";
	std::cout << std::endl;	
	std::cout << "Reverse Iterator vec without boucle for: ";
	reverse_iterator<vector<int>::iterator> rit = vec.rbegin();
	std::cout << *rit << " ";
	rit++;
	std::cout << *rit << " ";
	rit++;
	std::cout << *rit << " ";
	rit++;
	std::cout << *rit << " ";
	rit++;
	std::cout << *rit << " " << std::endl;
	rit = vec.rend() - 1;
	//std::cout << "coucou ";
	//std::cout << &(*vec.rend()) << std::endl;
	//std::cout << &(*rit);
	//std::cout << " coucou" << std::endl;
	std::cout << vec.rend() - vec.rbegin() << std::endl;
	std::cout << "rend() du vector: " << *vec.rend() << std::endl;
	std::cout << "rend() - 1 du vector: " << *rit << std::endl;
	std::cout << "Reverse Iterator vec with boucle for: ";
    for(reverse_iterator<vector<int>::iterator> it = vec.rbegin(); it != vec.rend() - 1; it++)
    {
		//write(1, "heyy ", 5); // to DEBUG
		std::cout << *it << " ";
	}
	std::cout << std::endl << std::endl;
	
	std::cout << "Test 3: ";

	vector<int>::iterator from(vec.begin());
	vector<int>::iterator until(vec.end());
	reverse_iterator<vector<int>::iterator> rev_end(from);
	reverse_iterator<vector<int>::iterator> rev_begin(until);
//	std::cout << "Compare adress of iterator vec.begin() and rev iterator(vec.begin()): " << std::endl;
//	std::cout << &(*from) << " ";
//	std::cout << &(*rev_end) << std::endl;
	while (rev_end != rev_begin) {
		std::cout << *rev_begin << " ";
		rev_begin++;
	}
	std::cout << std::endl;

	std::cout << " Test 4: Base " << std::endl << "rev.base(): "; 
	std::cout << *rev_end.base() << std::endl; // Probleme retour base pas bon
	for(reverse_iterator<vector<int>::iterator> rit = vec.rbegin(); rit != vec.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << std::endl << std::endl;

	std::cout << "Test 5: Constructors " << std::endl << std::endl;
	vector<float> v5(5, 42);
	// test default constructor
	std::cout << "test default constructor: " << " ";
	reverse_iterator<vector<int>::iterator> r;
	// test constructor 1
	std::cout << "test initialization constructor: " << std::endl;
	reverse_iterator<vector<float>::iterator> rev1(v5.begin());
	vector<float>::iterator i = v5.end();
	reverse_iterator<vector<float>::iterator> rev2(i);
	reverse_iterator<vector<float>::iterator> rev3(reverse_iterator<vector<float>::iterator> b);
	std::cout << std::endl;
	//test operator=
	std::cout << "test operator=() and operator*(): " << std::endl;
	vector<float> vct;
	vector<float>::iterator it = vct.begin(); (void)it;
	vector<float>::reverse_iterator rit2(it);
	vector<float>::const_reverse_iterator crit(rit2);
	std::cout << std::endl;
	// test constructor copy
	std::cout << "test copy constructor() " << std::endl;
	vector<float>::const_reverse_iterator crit2(rit2);
	std::cout << std::endl;

	std::cout << std::endl << "Test 6: Overload operators " << std::endl;
	
	std::cout << "Vector vct reverse: ";
	vct.push_back(1);
	vct.push_back(2);
	vct.push_back(3);
	vct.push_back(4);
	vct.push_back(5);
	vct.push_back(11);
	vct.push_back(12);
	vct.push_back(13);
	vct.push_back(14);
	vct.push_back(15);
	for(reverse_iterator<vector<float>::iterator> rit = vct.rbegin(); rit != vct.rend(); rit++)
		std::cout << *rit << " ";
	std::cout << std::endl;
	vector<float>::reverse_iterator rit3(vct.rbegin());
	rit3 = rit3 + 2;
	std::cout << "Increment rit de 2: " << *rit3 << std::endl;
	rit3 = rit3 - 2;
	std::cout << "Decrement rit de 2: " << *rit3 << std::endl;
	rit3++;
	rit3++;
	rit3++;
	rit3++;
	std::cout << "Increment rit de 4: " << *rit3 << std::endl;
	rit3--;
	std::cout << "Decrement rit: " << *rit3 << std::endl;
	rit3 += 2;
	std::cout << "Increment rit de 2: "<< *rit3 << std::endl;
	rit3 -= 2;
	std::cout << "Decrement rit de 2: " << *rit3 << std::endl;
	std::cout << "rit3[1]" << rit3[1] << std::endl;

	//vector<float>::const_iterator cit = vct.begin();
	//vector<float>::const_reverse_iterator crit1(it);
	
	////////////////////// TEST STACK //////////////////////////////

	std::cout << std::endl << CYAN << "************ Test Stack ************" << END_COLOR << std::endl << std::endl;

		
	std::cout << "  * Constructor of stack Test : *  " << std::endl;
	vector<int> myvec(3, 10);
	stack<int> first; 				    // empty stack
	std::cout << "size of empty stack: " << first.size() << std::endl;
	if (first.empty())
		std::cout << " test empty(), first is empty" << std::endl;
	
	stack<int, vector<int> > second (myvec);		// stack initialized to copy of deque
	std::cout << "size of stack copy of vector: " << second.size() << std::endl;
	if (!second.empty())
		std::cout << " test empty(), second is not empty" << std::endl;
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
