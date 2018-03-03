#include "stdafx.h"
#include "dlist.h"

namespace drw
{
	// default constructor. doesn't create anything
	template<class T>
	dlist<T>::dlist()
		:dSize(0), head(nullptr), tail(nullptr)
	{
	}

	// creates a list with one node with the data that is passed in.
	template<class T>
	dlist<T>::dlist(const T& data)
		:dSize(0), head(nullptr), tail(nullptr)
	{
		push_back(data);
	}

	// copies a list
	template<class T>
	dlist<T>::dlist(dlist<T>& copyList)
		:dSize(0), head(nullptr), tail(nullptr)
	{
		operator=(copyList);
	}

	// calls clear() because it does essentially that.
	template<class T>
	dlist<T>::~dlist()
	{
		clear();
	}

	template<class T>
	dlist<T>& dlist<T>::operator=(dlist<T>& copyList)
	{
		clear();							// delete what we have currently
		auto curr = copyList.begin();		// used to traverse the copyList
		while (curr != nullptr)				// this is where an iterator class would be useful, but I didn't make one so this will do.
		{
			push_back(curr->get_data());
			curr = curr->get_next();
		}

		return *this;
	}

	/////////////////////////////////////////////////
	/////////////	     ITERATORS       ////////////
	/////////////////////////////////////////////////

	// not really an iterator, but i need this for stuff
	template<class T>
	dnode<T>* dlist<T>::begin()
	{
		return head;
	}

	// not really an iterator, but i need this for stuff
	template<class T>
	dnode<T>* dlist<T>::end()
	{
		return tail;
	}

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
		return head->get_data();
	}

	// returns the data the tail is looking at
	// crashes if list is empty
	template<class T>
	T dlist<T>::back()
	{
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
		// if head is looking at nothing or there's one node, clear() it
		if (dSize <= 1)
		{
			clear();
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
		if (dSize <= 1)
		{
			clear();
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

	////////////////////////////////////////////////
	/////////////	   OPERATIONS       ////////////
	////////////////////////////////////////////////

	template<class T>
	void dlist<T>::remove(const T &data)
	{
		if (dSize == 0) return;

		auto curr = find(data);
		if (curr != nullptr)
		{
			// if dSize is 1, just clear everything
			// else if dSize is 2, check two cases where it can happen at head or tail and adjust accordingly
			// else dSize >= 3, check if at head or tail then somewhere in the middle
			if (dSize == 1)
			{
				clear();
			}
			else if (dSize == 2)
			{
				// if found at head, pop_front
				// else found at tail, pop_back
				if (curr == head)	pop_front();
				else				pop_back();
			}
			else
			{
				// if head, pop_front
				// else if tail, pop_back
				// else pop_curr
				if (curr == head)		pop_front();
				else if (curr == tail)	pop_back();
				else					pop_curr(curr);
			}
		}// if - found
	}

	// reverse list 
	// this will add on the reverse part of the list onto the current list's back.
	// then it will pop the number of elements it pushed onto the back from the front.
	// I initially created a copyList to push nodes from the back of the current list in reverse order,
	// but i realized it would double the destroys. one for the copy and one for my current list.
	template<class T>
	void dlist<T>::reverse()
	{
		if (dSize < 2) return;

		unsigned int numOfPops = 0;			// may overflow if there's a lot of items. used to pop_front a certain number of times
		auto curr = tail;					// start from teh tail
		while (curr != nullptr)				// use this way of traversing because i didn't make an iterator class
		{
			push_back(curr->get_data());	// push from the back onto the current list
			curr = curr->get_prev();		// go to previous node
			++numOfPops;					// does magic
		}
		
		for (int i = 0; i < numOfPops; ++i) pop_front();
	}

	// print the current list
	template<class T>
	void dlist<T>::print_list()
	{
		auto curr = head;
		std::cout << "<- head - ";
		while (curr != nullptr)
		{
			std::cout << "[ " << curr->get_data() << " ] - ";
			curr = curr->get_next();
		}
		std::cout << "tail ->\n";
	}

	// private function
	// only really used for remove()
	// does pointer rearranging. dSize gets decremented. deallocation of memory occurs.
	// a sort of visualization : ... <-[leftOfCurr]-> <-[curr]-> <-[rightOfCurr]-> ...
	template<class T>
	void dlist<T>::pop_curr(dnode<T> *&curr)
	{
		auto leftOfCurr = curr->get_prev();		// get the node before curr
		auto rightdOfCurr = curr->get_next();	// get the node after curr

		leftOfCurr->set_next(rightdOfCurr);		// have prevCurrNode's next look at nextCurrNode
		rightdOfCurr->set_prev(leftOfCurr);		// have nextCurrNode's prev look at prevCurrNode 

		delete curr;							// now delete the node sandwiched in between
		--dSize;								// decrement size
	}

	// private function
	// used to find a node with the data passed in
	// traverses the list from the head to the tail to find the data.
	template<class T>
	dnode<T>* dlist<T>::find(const T &data)
	{
		bool isFound = false;
		auto curr = head;
		while (curr != nullptr)
		{
			if (curr->get_data() == data)
			{
				isFound = true;
				break;
			}
			curr = curr->get_next();
		}
		return isFound? curr : nullptr;
	}
}// namespace drw