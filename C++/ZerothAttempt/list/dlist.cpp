#include "stdafx.h"
#include "dlist.h"

namespace drw
{
	template<class T>
	dlist<T>::dlist()
		:dSize(0), head(nullptr), tail(nullptr)
	{
	}

	// gotta traverse from head to tail and delete things behind it
	// or something like that, i think
	template<class T>
	dlist<T>::~dlist()
	{
		dnode<T> *curr = head;
		while (curr != nullptr)
		{
			dnode<T> *temp = curr;
			curr = curr->get_next();
			std::cout << "deleting :" << temp->get_data() << "\n";
			delete temp;
		}
	}

	/////////////////////////////////////////////////
	/////////////	     ITERATORS       ////////////
	/////////////////////////////////////////////////


	////////////////////////////////////////////////
	/////////////	     CAPACITY       /////////////
	////////////////////////////////////////////////

	// returns if bool of if size == 0
	template<class T>
	bool dlist<T>::empty()
	{
		return dSize == 0;
	}

	// returns the size of the list
	template<class T>
	int dlist<T>::size() const
	{
		return dSize;
	}

	////////////////////////////////////////////////
	/////////////	 ELEMENT ACCESS	    ////////////
	////////////////////////////////////////////////

	// returns the data the head is looking at
	template<class T>
	T dlist<T>::front()
	{
		return head->get_data();
	}

	// returns the data the tail is looking at
	template<class T>
	T dlist<T>::back()
	{
		return tail->get_data();
	}

	////////////////////////////////////////////////
	/////////////	    MODIFIERS       ////////////
	////////////////////////////////////////////////

	// adds nodes at the front
	template<class T>
	void dlist<T>::push_front(const T &data)
	{
		dnode<T>* new_node = new dnode<T>(data);

		// if head is looking at a node already
		if (head != nullptr)
		{
			new_node->set_next(head);	// new_node's next is looking at the current front
			head->set_prev(new_node);	// the current head node's prev is now looking at new_node

			head = new_node;			// head is now looking at new_node
		}
		else
		{
			head = new_node;			// head is now looking at new_node
			tail = new_node;			// since head was not looking at anything, this meant tail wasn't either - so now it is. 
		}

		++dSize;
	}
}// namespace drw