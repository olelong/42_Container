#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

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
								// Default constructor and copy constructor of Ctnr
				explicit stack(const container_type& c = container_type()) : c(c) {
				}

				stack& operator=(const stack& other) {
					this->c = other.c;
					return *this;
				}

				~stack() {
					this->c.clear();
				}

				// Element access

				value_type& top() { 
					return this->c.back();
				}

				const value_type& top() const {
					return this->c.back();
				}

				// Capacity

				bool empty() const {
					if (this->c.size() == 0)
						return true;
					return false;
				}

				size_type size() const {
					return this->c.size();
				}

				// Modifiers
				void push(const value_type& val) {
					this->c.push_back(val);
				}

				void pop() {
					this->c.pop_back();
				}

				template <typename U, typename Ctnr>
		  			friend bool operator==(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs);
				template <typename U, typename Ctnr>
		  			friend bool operator!=(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs);
				template <typename U, typename Ctnr>
		  			friend bool operator<(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs);
				template <typename U, typename Ctnr>
		  			friend bool operator>(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs);
				template <typename U, typename Ctnr>
		  			friend bool operator<=(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs);
				template <typename U, typename Ctnr>
		  			friend bool operator>=(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs);
			

			protected:
				container_type 		c;
				
		};

		// Non member relational operators
		template <typename U, typename Ctnr>
		  bool operator==(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs) {
			if (lhs.c == rhs.c)
				return true;
			return false;
		  }

		template <typename U, typename Ctnr>
			bool operator!=(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs) {
				if (lhs.c != rhs.c)
					return true;
				return false;
			}

		template <typename U, typename Ctnr>
			bool operator<(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs) {
				if (lhs.c < rhs.c)
					return true;
				return false;
			}

		template <typename U, typename Ctnr>
			bool operator<=(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs) {
				if (lhs.c <= rhs.c)
					return true;
				return false;
			}

		template <typename U, typename Ctnr>
			bool operator>(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs) {
				if (lhs.c > rhs.c)
					return true;
				return false;
			}

		template <typename U, typename Ctnr>
			bool operator>=(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs) {
				if (lhs.c >= rhs.c)
					return true;
				return false;
			}
}

#endif // STACK_HPP
