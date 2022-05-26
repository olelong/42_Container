
#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iostream>
# include <unistd.h>

namespace ft
{
	template <	class T,											// iterator::value_type
				class Category = std::random_access_iterator_tag,	// iterator::iterator_category
				class Distance = std::ptrdiff_t,					// iterator::difference_type
				class Pointer = T*,									// iterator::pointer
				class Reference = T&>								// iterator::reference
	class vector_iterator
	{
	public:
		typedef T			value_type;			// Type of the elements pointed by the iterator
		typedef Distance	difference_type;	// Type to represent the difference between two iterators
		typedef Pointer		pointer;			// Type to represent a pointer to an element pointed by the iterator
		typedef Reference	reference;			// Type to represent a reference to an element pointed by the iterator
		typedef Category	iterator_category;	// Category to which the iterator belongs to.
		
		// Canonical form
		vector_iterator() : p(NULL) {}
		vector_iterator(pointer p) : p(p) {}
		vector_iterator(const vector_iterator &it) {
			*this = it;
		}
		vector_iterator	&operator=(const vector_iterator& it) {
			this->p = it.p;
			return *this;
		}

		// Operators
			// Equality comparisons
		bool operator==(vector_iterator rhs) const {
			if (this->p == rhs.p)
				return true;
			return false;
		}

		bool operator!=(vector_iterator rhs) const {
			/* DEBUG for reverse_Iterator operator overload !=:
			char cond = !(*this == rhs) + '0';
			write(1, "h", 1);
			write(1, &cond, 1);
			write(1, "h", 1);
			std::cout << this->p << " " << rhs.p << std::endl;
			*/
			return !(*this == rhs);
		}

			// Dereferencing

		value_type	operator*() const {
			return *this->p;
		}

		value_type *operator->() {
			return this->p;
		}

		value_type &operator*() { // dereferencing as an lvalue
			return *this->p;
		}

			// Increment/Decrement

		vector_iterator	&operator++() { // pre incrementation
			this->p++;
			return *this;
		}
		
		vector_iterator	operator++(int) { // post incrementation
			vector_iterator tmp(*this);
			this->operator++();
			return tmp;
		}

		vector_iterator &operator--() {
			this->p--;
			return *this;
		}

		vector_iterator operator--(int) {
			vector_iterator tmp(*this);
			this->operator--();
			return tmp;
		}

		// Addition/substraction

		vector_iterator	operator+(int n) const {
			return this->p + n;
		}

		difference_type operator-(vector_iterator rhs) const {
			return this->p - rhs.p;
		}
		vector_iterator operator-(int n) const {
			return this->p - n;
		}

		// Inequality comparisons

		bool operator<(vector_iterator rhs) const {
			if (this->p < rhs.p)
				return true;
			return false;
		}

		bool operator>(vector_iterator lhs) const {
			return lhs < *this;
		}

		bool operator<=(vector_iterator lhs) const {
			return (*this < lhs || *this == lhs);
		}
		
		bool operator>=(vector_iterator lhs) const {
			return (lhs < *this || *this == lhs);
		}
	
		// Offset dereference

		value_type operator[](int i) const {
			vector_iterator tmp = *this + i;
			return *tmp;
		}

		value_type &operator[](int i) {
			vector_iterator tmp = *this + i;
			return *tmp;
		}

	private:
		pointer	p;	
	};

		template <class T, class Category, class Distance, class Pointer, class Reference>
			vector_iterator<T, Category, Distance, Pointer, Reference>
				operator+(int n, vector_iterator<T, Category, Distance, Pointer, Reference> vit) {
					return vit + n;
				}
}

#endif // ITERATOR_HPP
