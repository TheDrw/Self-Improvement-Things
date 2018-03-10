// Andrew Esberto
// first attempt to recreate the queue class mainly 4 lurningz
// To make it more interesting, I'll be implementing queue as a array and list
// The array is more similar to a vector but will grow and shrink.
// cans :	look at http://www.cplusplus.com/reference/queue/queue/ for reference
//			check for syntax things that I don't remember
//			use google for C++ things but not actual implementations of API
//
// can'ts:	look up actual implementations of API
//			use any STL that's not made by me unless it is too hard 
//			use bing
//			not eat pizza

#ifndef QUEUE_ARRAY
#define QUEUE_ARRAY

#include <memory>						// std::unique_ptr
#include <cstddef>					// std::size_t
#include <iostream>					// std::cout
#include <initializer_list>	//std::initializer_list

namespace drw
{ 
	template<class T>
	class queue_array
	{
	public:
		explicit queue_array();
		explicit queue_array(const T&);
		queue_array(std::initializer_list<T>);
		~queue_array();

		// member functions
		bool empty();
		std::size_t size() const;
		T &front() const;
		T	&back() const;
		void push(const T&);
		// emplace
		void pop();
		// swap

		// extras
		void print_queue();
		void print_array();

	private:
		void grow();
		void shrink();

	private:
		std::unique_ptr<T[]> dArray;	// gonna change the style on array a bit.
		std::size_t dSize;						// the d is used for differentiation.
		std::size_t dCapacity;				// it doesn't mean differentiation.
		std::size_t dFront;						// although, it could if you wanted it to.
		std::size_t dBack;
	};// class - queue_array 
}// namespace - drw
#endif
