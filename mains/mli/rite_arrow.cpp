#include <iostream>
#include <string>

#ifdef MINE
	#include "../../containers/vector.hpp"
#else
	#include <vector>
#endif

// --- Class foo
template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class foo
#define TESTED_TYPE foo<int>

using namespace NAMESPACE;

void printSize(vector<TESTED_TYPE>& v, int i) {
	(void)i;
	std::cout << v.size() << " " << v.capacity() << std::endl;
}


int		main(void)
{
	const int size = 5;
	vector<TESTED_TYPE> vct(size);
	vector<TESTED_TYPE>::reverse_iterator it(vct.rbegin());
	vector<TESTED_TYPE>::const_reverse_iterator ite(vct.rend());

	for (int i = 1; it != ite; ++i)
		*it++ = (i * 7);
	printSize(vct, 1);

	it = vct.rbegin();
	ite = vct.rbegin();
	
	/* KO */
	std::cout << " 1: " << *(ite) << std::endl;// 7 au lieu de 14
	std::cout << " 1: " << *(++ite) << std::endl;// 7 au lieu de 14
	std::cout << *(ite++) << std::endl; // 7 au lieu de 14
	std::cout << *ite++ << std::endl;// 14 au lieu de 21
	std::cout << *++ite << std::endl; // 28 au lieu de 35

	it->m();
	ite->m();
	
	/* OK */
	std::cout << " 2: " << *(++it) << std::endl;
	std::cout << *(it++) << std::endl;
	std::cout << *it++ << std::endl;
	std::cout << *++it << std::endl;

	/* KO  */
	std::cout << " 3: " << *(ite) << std::endl; // 28 au lieu de 35
	std::cout << " 3: " << *(--ite) << std::endl; // 21 au lieu de 28
	std::cout << *(ite--) << std::endl; // 21 au lieu de 28
	std::cout << *--ite << std::endl; // 7 au lieu de 14
	std::cout << *ite-- << std::endl; // 7 au lieu de 14

	(*it).m();
	(*ite).m();

	/* OK */
	std::cout << " 4: " << *(--it) << std::endl;
	std::cout << *(it--) << std::endl;
	std::cout << *it-- << std::endl;
	std::cout << *--it << std::endl;

	return (0);
}
