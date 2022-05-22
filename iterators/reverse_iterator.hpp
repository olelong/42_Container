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
					iterator_type base = this->it;
					return base;
				}

				// Operators Overload

				reference operator*() const {
					return *this->p;
				}
	
				reverse_iterator operator+(difference_type n) const {
					reverse_iterator tmp(*this);
					tmp.p = this->p - n;
					return tmp;
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
					reverse_iterator tmp(*this);
					tmp.p = this->p + n;
					return tmp;
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
					return &(operator*());
				}

				reference operator[](difference_type n) const {
					return this->p[n]; //this->p[n - 1];
				}

			private :
				pointer	p;
				iterator_type it;
		};
}

// Relational Operators

template <class Iterator> 
	bool operator==(const ft::reverse_iterator<Iterator>& lhs,
		const ft::reverse_iterator<Iterator>& rhs) {
			if (&(*lhs) != &(*rhs))
				return false;
			return true;
		}

template <class Iterator>
	bool operator!=(const ft::reverse_iterator<Iterator>& lhs,
		const ft::reverse_iterator<Iterator>& rhs) {
		return !(lhs == rhs);
	}


template <class Iterator>
	bool operator<(const ft::reverse_iterator<Iterator>& lhs,
		const ft::reverse_iterator<Iterator>& rhs) {
		return std::lexicographical_compare(lhs.rbegin(), lhs.rend(), rhs.begin(), rhs.rend());
	}

template <class Iterator>
	bool operator<=(const ft::reverse_iterator<Iterator>& lhs,
		const ft::reverse_iterator<Iterator>& rhs) {
		return !(rhs < lhs);
	}

template <class Iterator>
	bool operator>(const ft::reverse_iterator<Iterator>& lhs,
		const ft::reverse_iterator<Iterator>& rhs) {
		return (rhs < lhs);
	}

template <class Iterator>
	bool operator>=(const ft::reverse_iterator<Iterator>& lhs,
		const ft::reverse_iterator<Iterator>& rhs) {
		return !(lhs < rhs);
	}

#endif
