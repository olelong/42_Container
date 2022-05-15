#include "vector/vector.hpp"
#include <iostream>
#include <vector>

using namespace NAMESPACE;

int main()
{
	vector<int> v(3, 42);

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		std::cout << *it << std::endl;

	std::cout << v.front() << " " << v.back() << std::endl;

	if (!v.empty())
		std::cout << v.size() << std::endl;
	return (0);
}

// apres avoir fini ce main, tu peux faire l'operator= et le constructeur de copie
// (qui sont codes par defaut par le c++, donc n'hesite pas a ajouter des cout dedans
// pour verifier qu'il vient bien dans le tien)
