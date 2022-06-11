#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "../utils/iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
		class reverse_iterator
		{
			public :
				typedef				Iterator											iterator_type;
				typedef typename	ft::iterator_traits<Iterator>::iterator_category	iterator_category;
				typedef typename	ft::iterator_traits<Iterator>::value_type			value_type;
				typedef typename	ft::iterator_traits<Iterator>::difference_type		difference_type;
				typedef typename	ft::iterator_traits<Iterator>::pointer				pointer;
				typedef typename	ft::iterator_traits<Iterator>::reference			reference;
				
				// Constructors

				reverse_iterator() : it() { // point to no object
					//std::cout << "Default constructor called" << std::endl;
					//base_iterator is value-initialized
				}
				
				explicit reverse_iterator(iterator_type it) : it(it){ // : p(pointer()) {
					//std::cout << "constructor 1 called" << std::endl;
					//this->p = &(*it);
				}
				
				template <class Iter>
					reverse_iterator(const reverse_iterator<Iter>& rev_it) : it(rev_it.base()) {
						//std::cout << "copy constructor called" << std::endl;
						//this->p = &(*rev_it);
					}

				// Operators Assignment =
				template<class U>
				reverse_iterator& operator=(const reverse_iterator<U>& other) {
					//std::cout << "template operator=" << std::endl;
					//this->p = &(*other);
					this->it = other.base();
					return *this;
				}
				
				// Base()

				iterator_type base() const {
					//std::cout << "in base()" << std::endl;
					//iterator_type tmp(this->p);
					//tmp++;
					return this->it;//tmp;
				}

				// Operators Overload

				reference operator*() const {
				//	std::cout << "in operator*" << std::endl;
					//iterator_type tmp = this->p;
					//return *(this->p);
					iterator_type tmp = this->it;
					return (*--tmp);
				}
	
				reverse_iterator operator+(difference_type n) const {
					//std::cout << "in operator+()" << std::endl;
					reverse_iterator rev(this->base() - n);
					return rev;
				}

				reverse_iterator& operator++() { // pre increment
					//std::cout << "in operator++()" << std::endl;
					this->it--;
					return *this;
				}

				reverse_iterator operator++(int) { // post increment
				//	std::cout << "in second operator++()" << std::endl;
					reverse_iterator tmp(*this);
					//reverse_iterator tmp = *this;
					this->operator++();
					return tmp;
				}

				reverse_iterator& operator+=(difference_type n) {
					//std::cout << "in operator+=()" << std::endl;
					this->it -= n;
					return *this;
				}

				reverse_iterator operator-(difference_type n) const {
					//std::cout << "in operator-()" << std::endl;
					return reverse_iterator(this->base() + n);
				}

				reverse_iterator& operator--() { // pre increment
					this->it++;
				//	std::cout << "in operator--()" << std::endl;
					return *this;
				}

				reverse_iterator operator--(int) { // post increment
				//	std::cout << "in second operator--()" << std::endl;
					reverse_iterator tmp(*this);
					//reverse_iterator tmp = *this;
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
					return &(operator*());
					//return this->it;
				}

				reference operator[](difference_type n) const {
				//	std::cout << "in operator[]()" << std::endl;
					reverse_iterator rev = *this + n;
					return *rev;
				}

			protected :
				//pointer	p;
				iterator_type it;
		};

	// Relational Operators non member

	template <class Iterator1, class Iterator2> 
		bool operator==(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
			//	std::cout << "in non member operator==()" << std::endl;
				if ( lhs.base() == rhs.base())
					return true;
				return false;
		}

	template <class Iterator1, class Iterator2>
		bool operator!=(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
				//std::cout << "in non member operator!=()" << std::endl;
			/* DEBUG
			char cond = (lhs.base() != rhs.base()) + '0';
			write(1, &cond, 1);
			*/
			return lhs.base() != rhs.base();
		}

	template <class Iterator1, class Iterator2>
		bool operator<(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
				//std::cout << "in non member operator<()" << std::endl;
			//return !(lhs.base() > rhs.base());
			return (lhs.base() > rhs.base());
		}

	template <class Iterator1, class Iterator2>
		bool operator<=(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
			//	std::cout << "in non member operator<=()" << std::endl;
			//return !(lhs.base() >= rhs.base());
			return (lhs.base() >= rhs.base());
		}

	template <class Iterator1, class Iterator2>
		bool operator>(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
			//	std::cout << "in non member operator>()" << std::endl;
			//return !(lhs.base() < rhs.base());
			return (lhs.base() < rhs.base());
		}

	template <class Iterator1, class Iterator2>
		bool operator>=(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
			//	std::cout << "in non member operator>=()" << std::endl;
			return (lhs.base() <= rhs.base());
			//return !(lhs.base() <= rhs.base());
		}

	// operators +/- non member

	template <class Iterator>
		ft::reverse_iterator<Iterator> operator+(typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it) {
			//std::cout << "in non member operator+()" << std::endl;
			return rev_it + n;
		}

	template <class Iterator1, class Iterator2>
		typename ft::reverse_iterator<Iterator1>::difference_type operator-(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
			//std::cout << "in non member operator-()" << std::endl;
			return rhs.base() - lhs.base();
		}
}

#endif
