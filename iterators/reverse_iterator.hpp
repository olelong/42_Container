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
				}
				
				explicit reverse_iterator(iterator_type it)
				{
					value_type v = *it;
					pointer tmp = &v;
					this->p = tmp;//&(*it); // Construct a reverse iterator from original iterator it
					//except that it iterates through its pointed elements in the reverse order.
					//this->it = v;
				}
				
				/*template <class Iter>
					reverse_iterator(const reverse_iterator<Iter>& rev_it)
					{
						this->p = &(*rev_it);
					}*/
				
				// Base()

				iterator_type base() const {
					iterator_type base = this->it;
					return base; // + 1; decalage de -1 par rapport a l'iterateur de base
				}

				// Operators Overload

				reference operator*() const
				{
					
				}

			private :
				pointer	p;
				iterator_type it;
		};
}

template <class Iterator>
	bool operator!=(const ft::reverse_iterator<Iterator>& lhs,
		const ft::reverse_iterator<Iterator>& rhs) {
		if (lhs != rhs)
			return true;
		return false;
	}
#endif
