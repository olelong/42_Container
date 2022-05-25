#ifndef STACK_HPP
# define STACK_HPP

#include "../vector/vector.hpp"

namespace ft
{
	template <	class T, 						// Type of element stored
				class Container = ft::vector<T> >	// Type of underlying container to use to store the elements
		class stack
		{
			public :
				typedef				Container					container_type;
				typedef	typename	Container::value_type		value_type;
				typedef typename	Container::size_type		size_type;

				// Constructors/Destructors
								// Default constructor and copy constructor of ctnr
				explicit stack(const container_type& ctnr = container_type()) : _ctnr(ctnr) {
					this->_size = ctnr.size();
				}

				~stack()
				{
		//			for (size_type i = 0; i < this->_size; i++)
//						std::allocator<T>.destroy(this->arr + i);
//					std::allocator<T>.deallocate(this->arr, this->_size);
				}

				// Element access

				value_type& top() { // need to fill the array before
					//return this->arr[this->_size - 1];
				}

				// Capacity

				bool empty() const {
					if (this->_size == 0)
						return true;
					return false;
				}

				size_type size() const {
					return this->_ctnr.size();
				}

				// Modifiers

			private :
				container_type _ctnr;
				size_type		_size;

		};
}

#endif // STACK_HPP
