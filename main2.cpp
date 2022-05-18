#include "vector/vector.hpp"
#include <iostream>
#include <vector>

using namespace NAMESPACE;

int main()
{
	vector<int> v(3, 42);

	std::cout << "v: ";
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

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
	std::cout << std::endl << "v3[0]: " << v3[0] << std::endl;

	vector<int> v4;
	if (v4.empty())
		std::cout << "Default Constructor is empty" << std::endl;
	
	return (0);
}

// apres avoir fini ce main, tu peux faire l'operator= et le constructeur de copie
// (qui sont codes par defaut par le c++, donc n'hesite pas a ajouter des cout dedans
// pour verifier qu'il vient bien dans le tien)
