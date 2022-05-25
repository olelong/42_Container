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

				reverse_iterator() : p(NULL) { // point to no object
					value_type val;
					iterator_type it(val); // base_iterator is value-initialized
					this->it = it;
				}
				
				explicit reverse_iterator(iterator_type it) {
					value_type v = *it;
					pointer tmp = &v;
					this->p = tmp;//&(*it); // Construct a reverse iterator from original iterator it
					this->it = it;
				}
				
				/* Need enable_if
				template <class Iter>
					reverse_iterator(const reverse_iterator<Iter>& rev_it) {
						this->p = &(*rev_it);
					}*/
				
				// Base()

				iterator_type base() const {
					iterator_type base = this->it;// - 1; error segfault in mai error segfault in main
					return base;
				}

				// Operators Overload

				reference operator*() const {
					return *this->p;
				}
	
				reverse_iterator operator+(difference_type n) const {
			//		reverse_iterator tmp(*this);
			//		tmp.p = this->p - n;
			//		return tmp;
					return this->p - n;
				}

				reverse_iterator& operator++() { // pre increment
					this->p--;
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
					//reverse_iterator tmp(*this);
				//	tmp.p = this->p + n;
				//	return tmp;
					return this->p + n;
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
					//return &(operator*());
				}

				reference operator[](difference_type n) const {
					reverse_iterator rev = *this + n;
					return *rev;
					//return this->p[n]; //this->p[n - 1];
				}

			private :
				pointer	p;
				iterator_type it;
		};

	// Relational Operators non member

	template <class Iterator> 
		bool operator==(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
				//if (&(*lhs) != &(*rhs))
				//	return false;
				//return true;
				return lhs == rhs;
		}

	template <class Iterator>
		bool operator!=(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			//return !(lhs == rhs);
			return lhs != rhs;
		}

	template <class Iterator>
		bool operator<(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			if (lhs > rhs)
				return false;
			return true;
			//return std::lexicographical_compare(lhs.rbegin(), lhs.rend(), rhs.begin(), rhs.rend());
		}

	template <class Iterator>
		bool operator<=(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			if (lhs >= rhs)
				return false;
			return true;
			//return !(rhs < lhs);
		}

	template <class Iterator>
		bool operator>(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			if (lhs < rhs)
				return false;
			return true;
		}

	template <class Iterator>
		bool operator>=(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			if (lhs <= rhs)
				return false;
			return true;
		}

	// operators +/- non member

	template <class Iterator>
		ft::reverse_iterator<Iterator> operator+(typename ft::reverse_iterator<Iterator>::difference_type n, const ft::reverse_iterator<Iterator>& rev_it) {
			//reverse_iterator tmp(rev_it);
			//&(*tmp) = &(*rev_it) + n;
			//return tmp;
			return rev_it + n;
		}

	template <class Iterator>
		typename ft::reverse_iterator<Iterator>::difference_type operator-(const ft::reverse_iterator<Iterator>& lhs,
			const ft::reverse_iterator<Iterator>& rhs) {
			return lhs - rhs;
		}
}

#endif
