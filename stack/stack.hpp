#ifndef STACK_HPP
# define STACK_HPP

#include <deque>

namespace ft
{
	template <	class T, 						// Type of element stored
				class Container = std::deque<T> >	// Type of underlying container to use to store the elements
		class stack
		{
			public :
				typedef				Container					container_type;
				typedef	typename	Container::value_type		value_type;
				typedef typename	Container::size_type		size_type;

				// Constructors/Destructors
								// Default constructor and copy constructor of ctnr
				explicit stack(const container_type& ctnr = container_type()) {
					/*this->_size = ctnr.size();
					if (_size > 0)
						for(size_t i = 0; i < _size; i++)
							this->arr[i] = ctnr;
*/
					ctnr(arr);
				}

				~stack()
				{
		//			for (size_type i = 0; i < this->_size; i++)
//						std::allocator<T>.destroy(this->arr + i);
//					std::allocator<T>.deallocate(this->arr, this->_size);
				}

				size_type size() const {
					return this->ctnr.size();
				}

			private :
				container_type	ctnr;
				T*				arr;
				size_type		_size;

		};
}

#endif // STACK_HPP
