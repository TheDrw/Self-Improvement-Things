#include "stdafx.h"
#include "dforward_list.h"

namespace drw
{
	template<class T>
	dforward_list<T>::dforward_list()
		:head(nullptr)
	{
	}

	template<class T>
	dforward_list<T>::dforward_list(const T &data)
		:head(nullptr)
	{
		push_front(data);
	}

	template<class T>
	dforward_list<T>::dforward_list(dforward_list<T> &copyList)
		:head(nullptr)
	{
		operator=(copyList);
	}

	// breaker of chains, er i mean links.
	// in this case, deletes the forward_list.
	template<class T>
	dforward_list<T>::~dforward_list()
	{
		clear();
	}

	template<class T>
	dforward_list<T>& dforward_list<T>::operator=(dforward_list<T> &copyList)
	{
		clear();
		auto curr = copyList.begin();
		while (curr != nullptr)
		{
			push_front(curr->get_data());
			curr = curr->get_next();
		}
		reverse();	// items in the list will be pushed from the front, so we'll have to reverse it afterwards
		return *this;
	}

	/////////////////////////////////////////////////
	/////////////	     ITERATORS       ////////////
	/////////////////////////////////////////////////

	// not an iterator, but i need this
	template<class T>
	dnode<T>* dforward_list<T>::begin()
	{
		return head;
	}

	/////////////////////////////////////////////////
	/////////////	     CAPACITY       /////////////
	/////////////////////////////////////////////////

	// checks if list is empty
	// if head is nullptr, then it has nothing. it also knows nothing.
	//
	template<class T>
	bool dforward_list<T>::empty()
	{
		return head == nullptr;
	}

	////////////////////////////////////////////////
	/////////////	 ELEMENT ACCESS	    ////////////
	////////////////////////////////////////////////

	// access first element. goes through a wormhole if list is empty
	template<class T>
	T dforward_list<T>::front()
	{
		return head->get_data();
	}

	////////////////////////////////////////////////
	/////////////	    MODIFIERS       ////////////
	////////////////////////////////////////////////

	// pushes data at the front of the list
	template<class T>
	void dforward_list<T>::push_front(const T &data)
	{
		auto new_node = new dnode<T>(data);

		// if empty, have head point to new_node
		// else new_node points to what head is looking at, and head is reassigned to look at new_node
		if (empty())
		{
			head = new_node;
		}
		else
		{
			new_node->set_next(head);
			head = new_node;
		}
	}

	// pops the node at the front of the list. deallocation of memory occurs.
	template<class T>
	void dforward_list<T>::pop_front()
	{
		// if empty fwdlist
		if (empty()) return;

		// if one node, delete it and reset head
		if (head->get_next() == nullptr)
		{
			delete head;
			head = nullptr;
			return;
		}
		
		// if we hit here, this means we have more than one node in the list
		auto temp = head;
		head = head->get_next();
		delete temp;
	}

	// traverses list and delete nodes. deallocation of memory may occur.
	template<class T>
	void dforward_list<T>::clear()
	{
		auto curr = head;
		while (curr != nullptr)
		{
			auto temp = curr;
			curr = curr->get_next();
			delete temp;
		}

		head = nullptr;
	}

	////////////////////////////////////////////////
	/////////////	   OPERATIONS       ////////////
	////////////////////////////////////////////////

	// removes node with matching data. deallocation of memory may occur.
	template<class T>
	void dforward_list<T>::remove(const T &data)
	{
		if (empty()) return;

		auto curr = find(data);
		if (curr != nullptr)
		{
			// if matching data is at the head, pop_front
			// else if curr is at the head, just pop_front
			// else, this means the node is past the head; i.e somewhere in the middle or end
			if (head->get_next() == nullptr)	pop_front();
			else if (curr == head)				pop_front();
			else								pop_curr(curr);
		}
	}

	// reverses list with the idea we have limited resources.
	// also problem 8.2 in the book Elements of Programming Interviews o.O
	template<class T>
	void dforward_list<T>::reverse()
	{
		if (empty()) return;							// if empty list
		else if (head->get_next() == nullptr) return;	// if one node list

		auto curr = head;
		auto prev = (dnode<T>*)nullptr;
		auto next = (dnode<T>*)nullptr;

		while (curr != nullptr)
		{
			next = curr->get_next();
			curr->set_next(prev);
			prev = curr;
			curr = next;
		}

		head = prev;
	}

	////////////////////////////////////////////////
	/////////////	     EXTRAS	        ////////////
	////////////////////////////////////////////////

	// prints list by traversing from the front
	template<class T>
	void dforward_list<T>::print_list()
	{
		
		std::cout << "head - > ";
		auto curr = head;
		while (curr != nullptr)
		{
			std::cout << "[ " << curr->get_data() << " ] - > ";
			curr = curr->get_next();
		}
		std::cout << " end.\n";
	}

	// private function
	// pops nodes at the current addressed that's passed in
	// sort of visualization : ...- > [leftOfCurr] - > [curr] - > [curr->get_next()] - > ...
	template<class T>
	void dforward_list<T>::pop_curr(dnode<T>*& curr)
	{
		auto leftOfCurr = head;
		
		// because we don't have a prev pointer of curr, we have to traverse the list
		// up to the point before curr. we'll, technically, we do have a prev pointer in my node class, but it isn't wired to be used.
		while (leftOfCurr->get_next() != curr)	leftOfCurr = leftOfCurr->get_next();

		leftOfCurr->set_next(curr->get_next());	// set next to the point after curr
		delete curr;
	}

	// private function
	// finds the node with the data specified. 
	// if not found, it will return nullptr
	template<class T>
	dnode<T>* dforward_list<T>::find(const T &data)
	{
		auto curr = head;
		while (curr != nullptr)
		{
			if (curr->get_data() == data)	break; // if found
			curr = curr->get_next();
		}
		return curr;
	}

}// namespace drw