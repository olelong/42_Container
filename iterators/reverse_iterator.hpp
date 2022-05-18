#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public :
		typedef				Iterator										iterator_type;
		/*typedef typename	iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename	iterator_traits<Iterator>::value_type			value_type;
		typedef typename	iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename	iterator_traits<Iterator>::pointer				pointer;
		typedef typename	iterator_traits<Iterator>::reference			reference;*/

		// Constructors
		reverse_iterator() : p(NULL)
		{}

		explicit reverse_iterator(iterator_type it) {
			this->it = it;
			this->p = it.end();
		}

		template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it) {
				*this = rev_it;
			}

		//iterator_type base() const {}

		// Operators
		reference	operator*() const {
			return *this->p;//*this->it ?
		}

		reverse_
				

	private :
		iterator_type	it;
		pointer			p;
	};
}

#endif // REVERSE_ITERATOR_HPP
