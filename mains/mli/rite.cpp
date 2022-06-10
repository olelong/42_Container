#include <iostream>
#include <string>

#ifdef MINE
	#include "../../containers/vector.hpp"
#else
	#include <vector>
#endif

using namespace NAMESPACE;

#define TESTED_TYPE int
void printSize(vector<int> v) {
	std::cout << "size: " << v.size() << " capacity: " << v.capacity() << std::endl;
}

int		main(void)
{
	const int size = 5;
	vector<TESTED_TYPE> vct(size);
	vector<TESTED_TYPE>::iterator it_ = vct.begin();
	vector<TESTED_TYPE>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
	{
		vct[i] = (i + 1) * 5;
		std::cout << vct[i]  << " ";
	}
	std::cout << std::endl;
	printSize(vct);

	std::cout << (it_ == it.base()) << std::endl; 		//OK
	std::cout << (it_ == (it + 3).base()) << std::endl; //OK

	std::cout << *(it.base() + 1) << std::endl; 		//OK
	std::cout << *(it - 3) << std::endl; 						//KO
	std::cout << *(it - 3).base() << std::endl; 		//OK
	it -= 3;
	std::cout << *it.base() << std::endl;				//OK

	std::cout << "TEST OFFSET" << std::endl;
	std::cout << *(it) << std::endl;							//KO
	std::cout << *(it).base() << std::endl;				//OK
	std::cout << *(it - 0) << std::endl;						//KO
	std::cout << *(it - 0).base() << std::endl;			//OK
	std::cout << *(it - 1).base() << std::endl;			//OK
	// Erreur du au dereferencement de it donc au pointeur

	return (0);
}
