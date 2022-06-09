#include <iostream>
#include <string>

#ifdef MINE
	#include "../../vector/vector.hpp"
#else
	#include <vector>
#endif

using namespace NAMESPACE;

#define TESTED_TYPE int

void printSize(vector<int> v) {
	std::cout << v.size() << " " << v.capacity() << std::endl;
}


int		main(void)
{
	const int size = 5;
	vector<TESTED_TYPE> vct(size);
	vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
	vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
	{
		it[i] = (size - i) * 5;
		std::cout << it[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "1: " << *it << std::endl;
	
	it = it + 5;
	std::cout << "2: " << *it << std::endl;
	
	it = 1 + it;
	std::cout << "3: " << *it << std::endl;
	
	it = it - 4;
	std::cout << "4: " << *it << std::endl;
	
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "ite: " << *ite << " it: " << *it << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl << std::endl;
	//std::cout << "ite + 3: " << (*ite + 3) << " it: " << *it << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;
	//std::cout << "ite: " << &(*ite) << " it: " << &(*it) << std::endl;
	ite = ite + 3;
	//std::cout << (ite == it) << std::endl;
	std::cout << "ite + 3: "; ite.base().printAddress(); std::cout << " it: " << &(*it) << std::endl;

	printSize(vct);
	return (0);
}
