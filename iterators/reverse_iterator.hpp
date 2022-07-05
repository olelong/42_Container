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
					//base_iterator is value-initialized
				}
				
				explicit reverse_iterator(iterator_type it) : it(it){}
				
				template <class Iter>
					reverse_iterator(const reverse_iterator<Iter>& rev_it) : it(rev_it.base()) {}

				// Operators Assignment =
				template<class U>
				reverse_iterator& operator=(const reverse_iterator<U>& other) {
					this->it = other.base();
					return *this;
				}
				
				// Base()
				iterator_type base() const {
					return this->it;
				}

				// Operators Overload

				reference operator*() const {
					iterator_type tmp = this->it;
					return (*--tmp);
				}
	
				reverse_iterator operator+(difference_type n) const {
					reverse_iterator rev(this->base() - n);
					return rev;
				}

				reverse_iterator& operator++() { // pre increment
					//std::cout << "pre operator++() called" << std::endl;
					//std::cout << "pre ++ it key: " << this->it->first << std::endl;
					//std::cout << "pre ++ it value: " << this->it->second << std::endl;
					this->it--;
					//std::cout << "pre ++ it key after: " << this->it->first << std::endl;
					//std::cout << "pre ++ it value after: " << this->it->second << std::endl;
					//std::cout << " it--: " << *this << std::endl;
					return *this;
				}

				reverse_iterator operator++(int) { // post increment
					//std::cout << "post operator++() called" << std::endl;
					reverse_iterator tmp(*this);
				//	std::cout << "post ++ it key_value: " << tmp->first << std::endl;
					this->operator++();
				//	std::cout << "post ++ it key_value after: " << tmp->first << std::endl;
					return tmp;
				}

				reverse_iterator& operator+=(difference_type n) {
					this->it -= n;
					return *this;
				}

				reverse_iterator operator-(difference_type n) const {
					return reverse_iterator(this->base() + n);
				}

				reverse_iterator& operator--() { // pre increment
					//std::cout << "post -- it key_value: " << this->it->first << std::endl;
					this->it++;
					//std::cout << "post -- it key_value after: " << this->it->first << std::endl;
					return *this;
				}

				reverse_iterator operator--(int) { // post increment
					reverse_iterator tmp(*this);
				//	std::cout << "post -- it key_value: " << tmp->first << std::endl;
					this->operator--();
					//std::cout << "post -- it key_value after: " << tmp->first << std::endl;
					return tmp;
				}
				
				reverse_iterator& operator-=(difference_type n) {
					this->it += n;
					return *this;
				}

				pointer operator->() const {
					return &(operator*());
				}

				reference operator[](difference_type n) const {
					reverse_iterator rev = *this + n;
					return *rev;
				}

			protected :
				iterator_type it;
		};

	// Relational Operators non member

	template <class Iterator1, class Iterator2> 
		bool operator==(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
				if ( lhs.base() == rhs.base())
					return true;
				return false;
		}

	template <class Iterator1, class Iterator2>
		bool operator!=(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
			return lhs.base() != rhs.base();
		}

	template <class Iterator1, class Iterator2>
		bool operator<(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
			return (lhs.base() > rhs.base());
		}

	template <class Iterator1, class Iterator2>
		bool operator<=(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
			return (lhs.base() >= rhs.base());
		}

	template <class Iterator1, class Iterator2>
		bool operator>(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
			return (lhs.base() < rhs.base());
		}

	template <class Iterator1, class Iterator2>
		bool operator>=(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
			return (lhs.base() <= rhs.base());
		}

	// operators +/- non member

	template <class Iterator>
		ft::reverse_iterator<Iterator> operator+(typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it) {
			return rev_it + n;
		}

	template <class Iterator1, class Iterator2>
		typename ft::reverse_iterator<Iterator1>::difference_type operator-(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
			return rhs.base() - lhs.base();
		}
}

#endif
