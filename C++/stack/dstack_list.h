// Andrew Esberto
// first attempt to recreate the stack class mainly 4 lurningz
// To make it more interesting, I'll be implementing stack as a array and list
// This is fairly trivial and is pretty much just a doubly linked list with less functionality 
// Instead of bringing the dnode class from lists, i'll just put it in the header and avoid linking issues
// cans :	look at http://www.cplusplus.com/reference/stack/stack/ for reference
//			check for syntax things that I don't remember
//			use google for C++ things but not actual implementations of API
//
// can'ts:	look up actual implementations of API
//			use any STL that's not made by me unless it is too hard 
//			use bing
//			not eat pizza

#ifndef DSTACK_LIST
#define DSTACK_LIST

#include <iostream>	// std::cout

namespace drw
{
	template<class T>
	class dstack_list
	{
	public:
		explicit dstack_list();
		explicit dstack_list(const T&);
		~dstack_list();

		// member functions
		bool empty();
		int size() const;
		T top() const;
		void push(const T&);
		//emplace
		void pop();
		//swap

		// extras
		void print_stack();

	private:
		template<class T>
		class dnode
		{
		public:
			dnode(const T&d)
				:prev(nullptr), next(nullptr)
			{ data = d; }
			~dnode() {}

			// SETTERS
			void set_prev(dnode<T>* prev_node) { prev = prev_node; }
			void set_next(dnode<T>* next_node) { next = next_node; }

			// GETTERS
			dnode<T> *get_prev() { return prev; }
			dnode<T> *get_next() { return next; }
			T get_data() const { return data; }

		private:
			T data;
			dnode<T> *prev;
			dnode<T> *next;
		};

		dnode<T> *head;
		dnode<T> *tail;
		int dSize;
	};

}

#endif