
#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include "../iterators/vector_iterator.hpp"

namespace ft
{
	template<class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef T							value_type;
			typedef vector_iterator<value_type>	iterator;
			typedef size_t						size_type;
			typedef Alloc						allocator_type;
			
			// Constructors & Destructor
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
				this->arr = this->alloc.allocate(n);
				this->size = n;
				for (size_type i = 0; i < this->size; i++)
					this->arr[i] = val;
				(void)alloc;
			}

			~vector() {
				alloc.deallocate(this->arr, this->size);
			}
			
			// Iterators
			iterator begin() {
				return iterator(&arr[0]);
			}
			
			iterator end() {
				return iterator(arr + size);
			}

		private:
			value_type		*arr;
			allocator_type	alloc;
			size_type		size;
	};
}

#endif // VECTOR_HPP
