// Andrew Esberto
// first attempt to recreate the stack class mainly 4 lurningz
// To make it more interesting, I'll be implementing stack as a array and list
// This will be similar to vector since I'll be having the array grow and shrink
// The array will grow by twice the size when it hits the capacity,
// and shrink when the size is 1/4th the capacity
// cans :	look at http://www.cplusplus.com/reference/stack/stack/ for reference
//			check for syntax things that I don't remember
//			use google for C++ things but not actual implementations of API
//
// can'ts:	look up actual implementations of API
//			use any STL that's not made by me unless it is too hard 
//			use bing
//			not eat pizza

#ifndef DSTACK_ARRAY
#define DSTACK_ARRAY

#include <memory>	// std::unique_ptr
#include <iostream>	// std::cout

namespace drw
{
	template<class T>
	class dstack_array
	{
	public:
		explicit dstack_array();
		explicit dstack_array(const T&);
		~dstack_array();

		// member functions
		bool empty();
		std::size_t size() const;
		T top() const;
		void push(const T&);
		//emplace
		void pop();
		//swap

		// extras
		void print_stack();

	private:
		void grow();
		void shrink();
		void resizeArr();

	private:
		std::size_t dSize;
		std::size_t dCapacity;
		std::unique_ptr<T[]> arr;

	};// class dstack_array
}// namespace drw
#endif
