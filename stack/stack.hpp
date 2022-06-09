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
				}

				stack& operator=(const stack& other) {
					*this = other;
				}

				~stack()
				{
					this->_ctnr.clear();
				}

				// Element access

				value_type& top() { 
					return this->_ctnr.back();
				}

				// Capacity

				bool empty() const {
					if (this->_ctnr.size() == 0)
						return true;
					return false;
				}

				size_type size() const {
					return this->_ctnr.size();
				}

				// Modifiers
				void push(const value_type& val) {
					this->_ctnr.push_back(val);
				}

				void pop() {
					this->_ctnr.pop_back();
				}

			private :
				container_type 		_ctnr;
				
		};

		// Non member relational operators
		template <class T, class Container>
		  bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
			if (lhs.size() != rhs.size())
				return false;
			return true;
		  }

		template <class T, class Container>
			bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
				return !(lhs == rhs);
			}

		template <class T, class Container>
			bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
				if (lhs.size() < rhs.size())
					return true;
				return false;
			}

		template <class T, class Container>
			bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
				return (lhs == rhs || lhs < rhs);
			}

		template <class T, class Container>
			bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
				return rhs < lhs;
			}

		template <class T, class Container>
			bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
				//return !(lhs < rhs);
				return (lhs == rhs || rhs < lhs);
			}
}

#endif // STACK_HPP
