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
//
// Potenatial problem: because I don't know how to link files properly, if you have my dlist and dforward_list in the same header,
//		there will be issues when accessing the dnode class. so you have to do them separately. ¯\_(ツ)_/¯
//		this stuff is made just to learn the implementations, anyways, and not for use on projects (unless you want it to crash a lot).

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
		explicit dlist();
		explicit dlist(const T&);
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
		//sort // insert quickersort here
		void reverse();
		void print_list();

	private:
		void pop_curr(dnode<T>*&);
		dnode<T>* find(const T&);

	private:
		int dSize;
		dnode<T> *head;
		dnode<T> *tail;
	};// class dlist
}// namespace - drw

#endif // DLIST_H