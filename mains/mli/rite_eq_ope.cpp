#include <iostream>
#include <string>

#ifdef MINE
	#include "../../containers/vector.hpp"
#else
	#include <vector>
#endif

using namespace NAMESPACE;
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

#define TESTED_TYPE foo<int>

void printSize(vector<TESTED_TYPE> v) {
	std::cout << v.size() << " " << v.capacity() << std::endl;
}

template <typename Ite_1, typename Ite_2>
void ft_eq_ope(const Ite_1 &first, const Ite_2 &second, const bool redo = 1)
{/*
	std::cout << (first < second) << std::endl;
	std::cout << (first <= second) << std::endl;
	std::cout << (first > second) << std::endl;
*/	std::cout << (first >= second) << std::endl;
	if (redo)
		ft_eq_ope(second, first, 0);
	std::cout << std::endl;
}

int		main(void)
{
	const int size = 5;
	vector<TESTED_TYPE> vct(size);
	vector<TESTED_TYPE>::reverse_iterator it_0(vct.rbegin());
	vector<TESTED_TYPE>::reverse_iterator it_1(vct.rend());
	vector<TESTED_TYPE>::reverse_iterator it_mid;

	vector<TESTED_TYPE>::const_reverse_iterator cit_0 = vct.rbegin();
	vector<TESTED_TYPE>::const_reverse_iterator cit_1;
	vector<TESTED_TYPE>::const_reverse_iterator cit_mid;

	for (int i = size; it_0 != it_1; --i)
		*it_0++ = i;
	printSize(vct);
	it_0 = vct.rbegin();
	cit_1 = vct.rend();
	it_mid = it_0 + 3;
	cit_mid = it_0 + 3; cit_mid = cit_0 + 3; cit_mid = it_mid;
	/* OK */
	std::cout << std::boolalpha;
	std::cout << ((it_0 + 3 == cit_0 + 3) && (cit_0 + 3 == it_mid)) << std::endl;

	std::cout << "\t\tft_eq_ope:" << std::endl;
	// regular it
	std::cout << "REGULAR : " << std::endl; //OK
	ft_eq_ope(it_0 + 3, it_mid);
	ft_eq_ope(it_0, it_1);
	ft_eq_ope(it_1 - 3, it_mid);
	// const it
	std::cout << "CONST : " << std::endl;
	ft_eq_ope(cit_0 + 3, cit_mid);//2e/3e/5e/dernier
	ft_eq_ope(cit_0, cit_1);
	ft_eq_ope(cit_1 - 3, cit_mid);
	// both it
	std::cout << "BOTH : " << std::endl;
	ft_eq_ope(it_0 + 3, cit_mid);//2e/3e/5e/dernier
	ft_eq_ope(it_mid, cit_0 + 3);
	ft_eq_ope(it_0, cit_1);
	ft_eq_ope(it_1, cit_0);
	ft_eq_ope(it_1 - 3, cit_mid);//ALL
	ft_eq_ope(it_mid, cit_1 -3);
	
	return 0;
	}
