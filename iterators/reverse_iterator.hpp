#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{
	template <class Iterator>
		class reverse_iterator
		{
			public :
				typedef				Iterator											iterator_type;
				typedef typename	std::iterator_traits<Iterator>::iterator_category	iterator_category;
				typedef typename	std::iterator_traits<Iterator>::value_type			value_type;
				typedef typename	std::iterator_traits<Iterator>::difference_type		difference_type;
				typedef typename	std::iterator_traits<Iterator>::pointer				pointer;
				typedef typename	std::iterator_traits<Iterator>::reference			reference;
				
				// Constructors

				reverse_iterator() : it() { // point to no object
					//std::cout << "Default constructor called" << std::endl;
					//base_iterator is value-initialized
				}
				
				explicit reverse_iterator(iterator_type it) {
					//std::cout << "constructor 1 called" << std::endl;
					it--;
					this->it = it;
				}
				
				template <class Iter>
					reverse_iterator(const reverse_iterator<Iter>& rev_it) {
						//std::cout << "copy constructor called" << std::endl;
						this->it = &(*rev_it);
					}

				// Operators Assignment =
				template<class U>
				reverse_iterator& operator=(const reverse_iterator<U>& other) {
					std::cout << "template operator=" << std::endl;
					this->it = other.base();
					return *this;
				}
				
				// Base()

				iterator_type base() const {
					//std::cout << "in base()" << std::endl;
					iterator_type tmp(this->it);
					tmp++;
					return tmp;
				}

				// Operators Overload

				reference operator*() const {
					//std::cout << "in operator*" << std::endl;
					iterator_type tmp = this->it;
					return *tmp;
				}
	
				reverse_iterator operator+(difference_type n) const {
					//std::cout << "in operator+()" << std::endl;
					reverse_iterator rev(this->base() - n);
					return rev;
					//return this->it - n;
				}

				reverse_iterator& operator++() { // pre increment
					//std::cout << "in operator++()" << std::endl;
					this->it--;
					return *this;
				}

				reverse_iterator operator++(int) { // post increment
					//std::cout << "in second operator++()" << std::endl;
					reverse_iterator tmp(*this);
					this->operator++();
					return tmp;
				}

				reverse_iterator& operator+=(difference_type n) {
					//std::cout << "in operator+=()" << std::endl;
					this->it -= n;
					return *this;
				}

				reverse_iterator operator-(difference_type n) const {
					std::cout << "in operator-()" << std::endl;
					reverse_iterator rev(this->base() + n);
					return rev;
				}

				reverse_iterator& operator--() { // pre increment
					this->it++;
					//std::cout << "in operator--()" << std::endl;
					return *this;
				}

				reverse_iterator operator--(int) { // post increment
					//std::cout << "in second operator--()" << std::endl;
					reverse_iterator tmp(*this);
					this->operator--();
					return tmp;
				}
				
				reverse_iterator& operator-=(difference_type n) {
					//std::cout << "in operator-=()" << std::endl;
					this->it += n;
					return *this;
				}

				pointer operator->() const {
					//std::cout << "in operator->()" << std::endl;
					return this->it;
				}

				reference operator[](difference_type n) const {
					//std::cout << "in operator[]()" << std::endl;
					reverse_iterator rev = *this + n;
					return *rev;
				}

			protected :
				//pointer	p;
				iterator_type it;
		};

	// Relational Operators non member

	template <class Iterator> 
		bool operator==(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
				//std::cout << "in non member operator==()" << std::endl;
				return lhs.base() == rhs.base();
		}

	template <class Iterator>
		bool operator!=(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
				//std::cout << "in non member operator!=()" << std::endl;
			/* DEBUG
			char cond = (lhs.base() != rhs.base()) + '0';
			write(1, &cond, 1);
			*/
			return lhs.base() != rhs.base();
		}

	template <class Iterator>
		bool operator<(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
				//std::cout << "in non member operator<()" << std::endl;
			return !(lhs.base() > rhs.base());
		}

	template <class Iterator>
		bool operator<=(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			//	std::cout << "in non member operator<=()" << std::endl;
			return !(lhs.base() >= rhs.base());
		}

	template <class Iterator>
		bool operator>(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			//	std::cout << "in non member operator>()" << std::endl;
			return !(lhs.base() < rhs.base());
		}

	template <class Iterator>
		bool operator>=(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			//	std::cout << "in non member operator>=()" << std::endl;
			return !(lhs.base() <= rhs.base());
		}

	// operators +/- non member

	template <class Iterator>
		ft::reverse_iterator<Iterator> operator+(typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it) {
			std::cout << "in non member operator+()" << std::endl;
			reverse_iterator<Iterator> rev(rev_it.base() - n);
			return rev;
		}

	template <class Iterator>
		typename ft::reverse_iterator<Iterator>::difference_type operator-(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			std::cout << "in non member operator-()" << std::endl;
			std::cout << &(*rhs.base()) << " " << &(*lhs.base());
			int n = rhs.base() - lhs.base();
			std::cout << "n: " << n << std::endl;
			return n;
		}
}

#endif
