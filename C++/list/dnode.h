// Andrew Esberto
// first attempt to recreate the node class mainly 4 lurningz and for the dlist class
// cans :	look at http://www.cplusplus.com/reference/ for reference
//			check for syntax things that I don't remember
//			use google for C++ things but not actual implementations of API
//
// can'ts:	look up actual implementations of API
//			use any STL that's not made by me unless it is too hard 
//			use bing
//			not eat pizza

#ifndef DNODE_H
#define DNODE_H

#include <iostream>

namespace drw
{
	template<class T>
	class dnode
	{
	public:
		dnode(const T&);
		~dnode();

		// SETTERS
		void set_prev(dnode<T>*);
		void set_next(dnode<T>*);

		// GETTERS
		dnode<T> *get_prev();
		dnode<T> *get_next();
		T get_data() const;

	private:
		T data;
		dnode<T> *prev;
		dnode<T> *next;
	};
}// namespace - drw

#endif //DNODE_H