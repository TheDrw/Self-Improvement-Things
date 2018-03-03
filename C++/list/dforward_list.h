// Andrew Esberto
// first attempt to recreate the forward_list class mainly 4 lurningz
// I'm going to reuse the dnode class. Yes, it has a prev pointer, but I'm gonna just ignore it.
// cans :	look at http://www.cplusplus.com/reference/forward_list/forward_list/ for reference
//			check for syntax things that I don't remember
//			use google for C++ things but not actual implementations of API
//
// can'ts:	look up actual implementations of API
//			use any STL that's not made by me unless it is too hard 
//			use bing
//			not eat pizza
//
// Potenatial problem: because I don't know how to link files properly, if you have my dlist and dforward_list in the same header,
//		there will be issues when accessing the dnode class. so you have to do them separately. ¯\_(ツ)_/¯
//		this stuff is made just to learn the implementations, anyways, and not for use on projects (unless you want it to crash a lot).

#ifndef DFORWARD_LIST_H
#define DFORWARD_LIST_H

#include "dnode.cpp" // linker issues when using the .h, so .cpp will do
#include <iostream>

namespace drw 
{
	template<class T>
	class dforward_list
	{
	public:
		explicit dforward_list();
		explicit dforward_list(const T&);
		dforward_list(dforward_list<T>&);
		~dforward_list();
		dforward_list<T> &operator=(dforward_list<T>&);

		// fake iterators
		dnode<T> *begin();
		//dnode<T> *end();

		// capacity
		bool empty();
		//max_size

		// element access
		T front();

		// modifiers
		//assign
		//emplace_front
		void push_front(const T&);
		void pop_front();
		//emplace_after
		//insert_after
		//erase_after
		//swap
		//resize
		void clear();
		
		// operations
		//splice_after
		void remove(const T&);
		//remove_if
		//unique
		//merge
		//sort
		void reverse();

		//extras
		void print_list(); 

	private:
		void pop_curr(dnode<T> *&);
		dnode<T> *find(const T&);
	private:
		dnode<T> *head;
	};// class dforward_list
}// namespace drw

#endif