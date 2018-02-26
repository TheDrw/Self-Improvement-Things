#include "stdafx.h"
#include "dlist.h"

namespace drw
{
	template<class T>
	dlist<T>::dlist()
		:dSize(0), head(nullptr), tail(nullptr)
	{
		// not really sure what to put here
	}

	// calls clear() because it does essential that.
	template<class T>
	dlist<T>::~dlist()
	{
		clear();
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
	// crashes if list is empty
	template<class T>
	T dlist<T>::front()
	{
		// if (dSize == 0) return;
		return head->get_data();
	}

	// returns the data the tail is looking at
	// crashes if list is empty
	template<class T>
	T dlist<T>::back()
	{
		// if (dSize == 0) return;
		return tail->get_data();
	}

	////////////////////////////////////////////////
	/////////////	    MODIFIERS       ////////////
	////////////////////////////////////////////////

	// adds nodes at the front. dSize increments for every push
	// this creates a new node, so allocation of mammaries occurs
	template<class T>
	void dlist<T>::push_front(const T &data)
	{
		auto new_node = new dnode<T>(data);

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

		++dSize;						// size increases for every push
	}

	// removes first node of the list if it exsists. may decrement dSize
	// this will destroy the removed node, so deallocation of memory occurs
	template<class T>
	void dlist<T>::pop_front()
	{
		// if head is looking at nothing, do nothing
		if (dSize == 0) return;

		// if there's one object. this means head and tail are looking at the same node.
		if (dSize == 1)
		{
			delete head;
			dSize = 0;
			head = nullptr;
			tail = nullptr;
			return;
		}

		// if we reach this part, this means we have a list of two or more nodes.
		auto temp = head;			// have temp look at the front for reassignemnt of head
		head = head->get_next();	// head looks at the next node now and is reassigned
		head->set_prev(nullptr);	// because the front node is being deleted, the prev node head is now looking at has to point to nullptr
		delete temp;				// delete the node temp was looking at, which was the front
		--dSize;					// decrement size
	}

	// adds nodes at the back. dSize increments for every push
	// this creates a new node, so allocation of memory occurs.
	template<class T>
	void dlist<T>::push_back(const T &data)
	{
		auto new_node = new dnode<T>(data);

		// if tail is looking at a node already
		if (tail != nullptr)
		{
			new_node->set_prev(tail);	// new_node's prev is now looking at the current tail
			tail->set_next(new_node);	// the current tail node's next is now looking at new_node
			tail = new_node;			// tail is now looking at new_node
		}
		else
		{
			tail = new_node;			// tail is now looking at new_node
			head = new_node;			// since tail was not looking at anything, this meant head wasn't either - so now it is.
		}

		++dSize;						// dSize increases for every push
	}

	// removes the last node of the list if it exists. may decrement dSize
	// this will destroy the removed node, so deallocation of memory occurs.
	template<class T>
	void dlist<T>::pop_back()
	{
		// if tail's looking at nothing, do nothing
		if (dSize == 0) return;

		// if there's one node. this means head and tail are looking at teh same node.
		if (dSize == 1)
		{
			delete tail;
			tail = nullptr;
			head = nullptr;
			dSize = 0;
			return;
		}

		// if we reach this part, this means we have a list of two or more nodes.
		auto temp = tail;			// have temp look at teh tail for reassignment of tail
		tail = tail->get_prev();	// tail looks at the prev node now and is reassigned
		tail->set_next(nullptr);	// because the back node is being deleted, the next node tail is now looking at has to point to nullptr
		delete temp;				// delete the node temp was looking at, which was at the back
		--dSize;					// decrement size
	}


	// this will delete all the nodes. deallocation of memory will occur
	// dSize = 0, head and tail will point to nullptr
	template<class T>
	void dlist<T>::clear()
	{
		if (dSize == 0) return;

		auto curr = head;				// curr is used to traverse the list
		while (curr != nullptr)
		{
			auto temp = curr;			// temp will be used to store the current node then delete it after curr has moved fwd
			curr = curr->get_next();	// curr moves to the next node
			delete temp;				// delete node
		}

		head = nullptr;					// will get some errors without setting
		tail = nullptr;					// the head and tail to point at nullptr
		dSize = 0;						// it is safe to say there's nothing in the list so dSize is zilch 
	}
}// namespace drw