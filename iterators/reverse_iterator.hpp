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
				
				
			private :
		};
}

#endif
