
#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stdexcept>
# include "../iterators/vector_iterator.hpp"

namespace ft
{
	template<class T, class Alloc = std::allocator<T> >
	class vector
	{
		public:
			typedef 			T									value_type;
			typedef 			Alloc								allocator_type;
			typedef	typename	allocator_type::reference			reference;			
			typedef typename	allocator_type::const_reference		const_reference;			
			typedef	typename	allocator_type::pointer				pointer;			
			typedef typename	allocator_type::const_pointer		const_pointer;			
			typedef 			vector_iterator<value_type>			iterator;
			typedef 			vector_iterator<const value_type>	const_iterator;
			typedef 			size_t								size_type;
			

			// Constructors & Destructor
			explicit vector(const allocator_type& alloc = allocator_type()) {
				this->_alloc = alloc;
				this->arr = this->_alloc.allocate(0);
				this->_capacity = 0;
				this->_size = 0;
			}	

			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
				this->_alloc = alloc;
				this->arr = this->_alloc.allocate(n);
				this->_capacity = n;
				this->_size = n;
				for (size_type i = 0; i < this->_size; i++)
					this->arr[i] = val;
			}

			/* Need enable_if!
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocatr_type()) {
				this->_alloc = alloc;
				this->_size = last - first;
				this->arr = this->_alloc.allocate(this->_size);
				size_type i = 0;
				for(InputIterator it = first; it != last; it++, i++)
				{
					this->_arr[i] = *it;
				}
			}
			*/
			
			vector (const vector &x){
				this->arr = this->_alloc.allocate(0);
				*this = x;
			}
						
			~vector() {
				_alloc.deallocate(this->arr, this->_capacity);
			}
			
			// Operators=
			vector	&operator=(const vector& x) {
				this->_alloc.deallocate(this->arr, this->_size);
				this->arr = this->_alloc.allocate(x._size);
				for (size_type i = 0; i < x._size; i++)
					this->arr[i] = x.arr[i];
				this->_size = x._size;
				return *this;
			}

			// Iterators
			iterator begin() {
				return iterator(arr);
			}
			
			const_iterator begin() const {
				const_iterator ret(arr);
				return ret;
			}

			iterator end() {
				return iterator(arr + _size);
			}

			const_iterator end() const {
				const_iterator ret(arr + _size);
				return ret;
			}

			// Capacity
			size_type size() const { //problem name size avec variable private donc ajout d'un _devant la variable size 
				return _size;
			}

			bool empty() const {
				if (_size == 0)
					return true;
				return false;
			}
			
			// Element Access
			reference operator[] (size_type n) {
				return arr[n]; 
			}
			
			const_reference operator[] (size_type n) const{
				return arr[n]; 
			}

			reference at(size_type n) {
				if (n >= this->_size)
					throw std::out_of_range(this->out_of_range_what(n));
				return arr[n];
			}

			const_reference at(size_type n) const{
				if (n >= this->_size)
					throw std::out_of_range(this->out_of_range_what(n));
				return arr[n];
			}

			reference front(){
				return arr[0];
			}
			const_reference front() const{
				return arr[0];
			}
			reference back(){
				return arr[_size - 1];
			}
			const_reference back() const{
				return arr[_size - 1];
			}

			

			// Modifiers
			// Allocator
			
		private:
			pointer			arr;
			allocator_type	_alloc;
			size_type		_size; // cause size already taken by method
			size_type		_capacity; // allocated size of the vector

			// Get the error message for out_of_range exception
			std::string out_of_range_what(size_type n) const {
				std::stringstream ss;
				std::string what = "vector::_M_range_check: __n (which is ";
				ss << n;
				what.append(ss.str());
				what.append(") >= this->size() (which is ");
				ss.str("");
				ss << this->size();
				what.append(ss.str());
				what.push_back(')');
				return what;
			}
	};
}

#endif // VECTOR_HPP
