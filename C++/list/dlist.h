// Andrew Esberto
// first attempt to recreate the list class mainly 4 lurningz
// cans :	look at http://www.cplusplus.com/reference/list/list/ for reference
//			check for syntax things that I don't remember
//			use google for C++ things but not actual implementations of API
//
// can'ts:	look up actual implementations of API
//			use any STL that's not made by me unless it is too hard 
//			use bing
//			not eat pizza

#ifndef DLIST_H
#define DLIST_H

#include "dnode.cpp" // getting linker issues if i use .h - i know this is probably not best practices
#include <memory>
#include <iostream>

namespace drw
{
	template<class T>
	class dlist
	{
	public:
		dlist();
		dlist(const T&);
		dlist(dlist<T>&);
		~dlist();
		dlist<T> &operator=(dlist<T>&);

		// FAKE ITERATORS
		dnode<T> *begin();
		dnode<T> *end();
		
		// CAPACITY
		bool empty();
		int size() const;
		//int max_size();

		// ELEMENT ACCESS
		T front();
		T back();

		// MODIFIERS
		//assign
		//emplace_front
		void push_front(const T&);
		void pop_front();
		//emplace_back
		void push_back(const T&);
		void pop_back();
		//emplace
		//insert
		//erase
		//swap
		//resize
		void clear();

		// OPERATIONS
		//splice
		void remove(const T&);
		//remove_if
		//unique
		//merge
		//sort
		void reverse();
		void print_list();

	private:
		void pop_curr(dnode<T>*&);

	private:
		int dSize;
		dnode<T> *head;
		dnode<T> *tail;
	};// class dlist
}// namespace - drw

#endif // DLIST_H