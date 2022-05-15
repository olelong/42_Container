
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
			typedef 			T									value_type;
			typedef 			vector_iterator<value_type>			iterator;
			typedef 			size_t								size_type;
			typedef 			Alloc								allocator_type;
			typedef	typename	allocator_type::reference			reference;			
			typedef typename	allocator_type::const_reference		const_reference;			

			// Constructors & Destructor
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
				this->arr = this->alloc.allocate(n);
				this->_size = n;
				for (size_type i = 0; i < this->_size; i++)
					this->arr[i] = val;
				(void)alloc;
			}

			~vector() {
				alloc.deallocate(this->arr, this->_size);
			}
			
			// Iterators
			iterator begin() {
				return iterator(&arr[0]);
			}
			
			iterator end() {
				return iterator(arr + _size);
			}
/*
			reference front(){
				return *arr.begin();
			}
			reference back(){
				return *arr.end();
			}
			const_reference front() const{
				return *arr.begin();
			}*/
		/*	const_reference back() const{
				return *std::prev(.end());
			}*/
			/*const_reference back() const{
				return *v.end();
			}*/
			size_type size() const { //problem name size avec variable private donc ajout d'un _devant la variable size 
				return _size;
			}
			bool empty() const {
				if (_size == 0)
					return true;
				return false;
			}
		private:
			value_type		*arr;
			allocator_type	alloc;
			size_type		_size;
	};
}

#endif // VECTOR_HPP
