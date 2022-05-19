#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iterator>
# include "../vector/vector.hpp"

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
		reverse_iterator()
		{
		//	*this = NULL;
		//	this->it = 0; //initialiser l'iterateur de base par une valeur
		}

		explicit reverse_iterator(iterator_type it) {
			this->it = it;

		}
/*
		template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it) {
				*this = rev_it;
			}
*/
		//iterator_type base() const {}

		// Operators
/*		reference			operator*() const {
			return this;
		}

		reverse_iterator	operator+(difference_type n) const {
			reverse_iterator rev = this->it - n;
			return rev;
		}

*/		/*pre_increment*/
		reverse_iterator&	operator++() {
			reverse_iterator rev(*this);
			rev--;
			return rev;
			//this->it--;
		}
		/*post_increment*/
		reverse_iterator	operator++(int) {
			reverse_iterator rev(*this);
			++rev;
			return rev;
		}
/*
		reverse_iterator&	operator+=(difference_type n) {
			reverse_iterator rev = *this->it - n;
			return rev;
		}

		reverse_iterator	operator-(difference_type n) const {
			reverse_iterator rev = *this->it + n;
			return rev;
		}

*/		/*pre_increment*/
		reverse_iterator&	operator--() {
			reverse_iterator rev(*this);
			rev++;
			return *rev;
		}

		/*post_increment*/
		reverse_iterator	operator--(int) {
			reverse_iterator rev(*this);
			--rev;
			return rev;
		}

/*		reverse_iterator	operator-=(difference_type n) {
			reverse_iterator rev = *this->it + n;
			return rev;
		}

		pointer				operator->() const {
			return &(operator*());
		}

		reference			operator[](difference_type n) const {
			//return *this->it[n];
			return *this->it = n;
		}*/

	private :
		iterator_type		it;
	};
}

template <class Iterator>
	bool operator==(const_reverse_iterator<Iterator>& lhs,
		const_reverse_iterator<Iterator>& rhs) {
			if (lhs == rhs)
				return true;
			return false;
		}

template <class Iterator>
	bool operator!=(const_reverse_iterator<Iterator>& lhs,
		const_reverse_iterator<Iterator>& rhs) {
			if (lhs != rhs)
				return true;
			return false;
		}
/*
template <class Iterator>
	bool operator<(const_reverse_iterator<Iterator>& lhs,
		const_reverse_iterator<Iterator>& rhs) {
			if (lhs < rhs)
				return true;
			return false;
		}

template <class Iterator>
	bool operator<=(const_reverse_iterator<Iterator>& lhs, const_reverse_iterator<Iterator>& rhs) {
			if (lhs <= rhs)
				return true;
			return false;
		}

template <class Iterator>
	bool operator>(const_reverse_iterator<Iterator>& lhs,
		const_reverse_iterator<Iterator>& rhs) {
			if (lhs > rhs)
				return true;
			return false;
		}

template <class Iterator>
	bool operator>=(const_reverse_iterator<Iterator>& lhs,
		const_reverse_iterator<Iterator>& rhs) {
			if (lhs >= rhs)
				return true;
			return false;
		}

template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it) {
			return reverse_iterator(rev_it + n);
		}

template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs) {
			return reverse_iterator(rhs - lhs);
		}
*/
#endif // REVERSE_ITERATOR_HPP
