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
			

			private :
				container_type 		_ctnr;
				
		};

		// Non member relational operators
		template <typename U, typename Ctnr>
		  bool operator==(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs) {
			if (lhs._ctnr == rhs._ctnr)
				return true;
			return false;
		  }

		template <typename U, typename Ctnr>
			bool operator!=(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs) {
				if (lhs._ctnr != rhs._ctnr)
					return true;
				return false;
			}

		template <typename U, typename Ctnr>
			bool operator<(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs) {
				if (lhs._ctnr < rhs._ctnr)
					return true;
				return false;
			}

		template <typename U, typename Ctnr>
			bool operator<=(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs) {
				if (lhs._ctnr <= rhs._ctnr)
					return true;
				return false;
			}

		template <typename U, typename Ctnr>
			bool operator>(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs) {
				if (lhs._ctnr > rhs._ctnr)
					return true;
				return false;
			}

		template <typename U, typename Ctnr>
			bool operator>=(const stack<U,Ctnr>& lhs, const stack<U,Ctnr>& rhs) {
				if (lhs._ctnr >= rhs._ctnr)
					return true;
				return false;
			}
}

#endif // STACK_HPP
