#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include <unistd.h>

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

				reverse_iterator() : p(NULL) { // point to no object
					value_type val;
					iterator_type it(val); // base_iterator is value-initialized
					this->it = it;
				}
				
				explicit reverse_iterator(iterator_type it) {
					pointer tmp = &(*it);
					this->p = tmp;//&(*it); // Construct a reverse iterator from original iterator it
					this->it = it;
				}
				
				/* Need enable_if ?*/
				template <class Iter>
					reverse_iterator(const reverse_iterator<Iter>& rev_it) {
						this->p = &(*rev_it);
					}
				
				// Base()

				iterator_type base() const {
					return this->it;
				}

				// Operators Overload

				reference operator*() const {
					return *this->p;
				}
	
				reverse_iterator operator+(difference_type n) const {
					return this->p - n;
				}

				reverse_iterator& operator++() { // pre increment
					this->it--;
					return *this;
				}

				reverse_iterator operator++(int) { // post increment
					reverse_iterator tmp(*this);
					this->operator++();
					return tmp;
				}

				reverse_iterator& operator+=(difference_type n) {
					this->p -= n;
					return *this;
				}

				reverse_iterator operator-(difference_type n) const {
					reverse_iterator ret(this->p + n);
					return ret;
				}

				reverse_iterator& operator--() { // pre increment
					this->p++;
					return *this;
				}

				reverse_iterator operator--(int) { // post increment
					reverse_iterator tmp(*this);
					this->operator--();
					return tmp;
				}
				
				reverse_iterator& operator-=(difference_type n) {
					this->p += n;
					return *this;
				}

				pointer operator->() const {
					return this->p;
				}

				reference operator[](difference_type n) const {
					reverse_iterator rev = *this + n;
					return *rev;
				}

			private :
				pointer	p;
				iterator_type it;
		};

	// Relational Operators non member

	template <class Iterator> 
		bool operator==(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
				return lhs.base() == rhs.base();
		}

	template <class Iterator>
		bool operator!=(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			/* DEBUG
			char cond = (lhs.base() != rhs.base()) + '0';
			write(1, &cond, 1);
			*/
			return lhs.base() != rhs.base();
		}

	template <class Iterator>
		bool operator<(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			if (lhs.base() > rhs.base())
				return false;
			return true;
			//return std::lexicographical_compare(lhs.rbegin(), lhs.rend(), rhs.begin(), rhs.rend());
		}

	template <class Iterator>
		bool operator<=(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			if (lhs.base() >= rhs.base())
				return false;
			return true;
			//return !(rhs < lhs);
		}

	template <class Iterator>
		bool operator>(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			if (lhs.base() < rhs.base())
				return false;
			return true;
		}

	template <class Iterator>
		bool operator>=(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			if (lhs.base() <= rhs.base())
				return false;
			return true;
		}

	// operators +/- non member

	template <class Iterator>
		ft::reverse_iterator<Iterator> operator+(typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it) {
			return rev_it.base() + n;
		}

	template <class Iterator>
		typename ft::reverse_iterator<Iterator>::difference_type operator-(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			return lhs.base() - rhs.base();
		}
}

#endif
