#include "stdafx.h"
#include "dnode.h"

namespace drw
{
	template<class T>
	dnode<T>::dnode(const T &d)
		:prev(nullptr), next(nullptr), data(d)
	{}

	template<class T>
	dnode<T>::~dnode()
	{
		std::cout << "destroyed : " << data << "\n";
	}

	/////////////////////////////////////////////////
	/////////////	     SETTERS         ////////////
	/////////////////////////////////////////////////

	template<class T>
	void dnode<T>::set_prev(dnode<T>* prev_node)
	{
		prev = prev_node;
	}

	template<class T>
	void dnode<T>::set_next(dnode<T>* next_node)
	{
		next = next_node;
	}

	/////////////////////////////////////////////////
	/////////////	     GETTERS       ////////////
	/////////////////////////////////////////////////

	template<class T>
	dnode<T>* dnode<T>::get_prev()
	{
		return prev;
	}

	template<class T>
	dnode<T>* dnode<T>::get_next()
	{
		return next;
	}

	template<class T>
	T dnode<T>::get_data() const
	{
		return data;
	}
}// namespace drw

