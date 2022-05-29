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
					//	std::cout << "copy constructor called" << std::endl;
						this->it = &(*rev_it);
					}

				// Operators Assignment =
				template<class U>
				reverse_iterator& operator=(const reverse_iterator<U>& other) {
					//std::cout << "template operator=" << std::endl;
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
				//	std::cout << "in operator*" << std::endl;
					//iterator_type tmp(this->base());//this->it;
					//iterator_type tmp = this->base();//this->it;
					//iterator_type tmp(this->it);
					
					//iterator_type tmp = this->it;
					iterator_type tmp(this->it);
					
					//tmp--;
					return *tmp;
				}
	
				reverse_iterator operator+(difference_type n) const {
					//std::cout << "in operator+()" << std::endl;
					//reverse_iterator rev(this->base() - n);
					//reverse_iterator rev(this->it - n);
					reverse_iterator rev = this->it - n;
					//reverse_iterator rev(this->base() - n);
					return rev;
					//return this->it - n;
				}

				reverse_iterator& operator++() { // pre increment
					//std::cout << "in operator++()" << std::endl;
					this->it--;
					return *this;
				}

				reverse_iterator operator++(int) { // post increment
				//	std::cout << "in second operator++()" << std::endl;
					reverse_iterator tmp = *this;
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
					//reverse_iterator rev(this->base() + n);
					//reverse_iterator rev(this->base() + n);
					reverse_iterator rev(this->it + n);
					//Iterator tmp1(this->base() + n);
					//reverse_iterator rev(tmp1);
					return rev;
				}

				reverse_iterator& operator--() { // pre increment
					this->it++;
				//	std::cout << "in operator--()" << std::endl;
					return *this;
				}

				reverse_iterator operator--(int) { // post increment
				//	std::cout << "in second operator--()" << std::endl;
					//reverse_iterator tmp(*this);
					reverse_iterator tmp = *this;
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
				//std::cout << "in non member operator==()" << std::endl;
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
			reverse_iterator<Iterator> rev(rev_it.base() - n);
			return rev;
		}

	template <class Iterator1, class Iterator2>
		typename ft::reverse_iterator<Iterator1>::difference_type operator-(const ft::reverse_iterator<Iterator1>& lhs,
			const ft::reverse_iterator<Iterator2>& rhs) {
			//std::cout << "in non member operator-()" << std::endl;
			Iterator1 tmp1 = lhs.base();
			Iterator1 tmp2 = rhs.base();
			return  tmp2 - tmp1;
		}
}

#endif
