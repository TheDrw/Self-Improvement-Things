// Andrew Esberto
// first attempt to recreate the queue class mainly 4 lurningz
// To make it more interesting, I'll be implementing queue as a array and list
// cans :	look at http://www.cplusplus.com/reference/queue/queue/ for reference
//			check for syntax things that I don't remember
//			use google for C++ things but not actual implementations of API
//
// can'ts:	look up actual implementations of API
//			use any STL that's not made by me unless it is too hard 
//			use bing
//			not eat pizza

#ifndef QUEUE_SINGLY_LIST
#define QUEUE_SINGLY_LIST

#include <cstddef>		// std::size_t
#include <iostream>		// std::cout

namespace drw
{
	template<class T>
	class queue_singly_list
	{
	public:
		explicit queue_singly_list();
		explicit queue_singly_list(const T&);
		~queue_singly_list();

		// member functions
		bool empty();
		std::size_t size() const;
		T front() const;
		T back() const;
		void push(const T&);
		// emplace
		void pop();
		// swap

		void print_queue();

	private:
		// dnode class - a little modified to fit this class
		// put in here for convenience
		template<class T>
		class dnode
		{
		public:
			dnode(const T&d)
				: next(nullptr), data(d){}
			~dnode() {}

			// SETTERS
			void set_next(dnode<T>* next_node) { next = next_node; }

			// GETTERS
			dnode<T> *get_next() { return next; }
			T get_data() const { return data; }

		private:
			T data;
			dnode<T> *next;
		};

		dnode<T> *head;
		dnode<T> *tail;
		std::size_t dSize;
	};// class - queue_singly_list
}// namespace - drw
#endif //QUEUE_SINGLY_LIST