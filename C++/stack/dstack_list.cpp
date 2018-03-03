#include "stdafx.h"
#include "dstack_list.h"

namespace drw
{
	// default constructor
	template<class T>
	dstack_list<T>::dstack_list()
		: dSize(0), head(nullptr), tail(nullptr)
	{
	}

	// start a list with initial data
	template<class T>
	dstack_list<T>::dstack_list(const T &data)
	{
		push(data);
	}

	// deletes list
	template<class T>
	dstack_list<T>::~dstack_list()
	{
		auto curr = head;
		while (curr != nullptr)
		{
			auto temp = curr;
			curr = curr->get_next();
			delete temp;
		}
	}

	////////////////////////////////////////////////
	/////////////	 MEMBER FUNCTIONS    ///////////
	////////////////////////////////////////////////

	template<class T>
	bool dstack_list<T>::empty()
	{
		return dSize == 0;
	}

	template<class T>
	int dstack_list<T>::size() const
	{
		return dSize;
	}

	template<class T>
	T dstack_list<T>::top() const
	{
		return tail->get_data();
	}

	// pushes new item onto stack. size increments
	// allocation of memory occurs
	template<class T>
	void dstack_list<T>::push(const T &data)
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

	// pop newest item on the stack. size decrements
	// deallocation of memory may occur
	template<class T>
	void dstack_list<T>::pop()
	{
		if (empty()) return;
		if (dSize == 1)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}

		// if we reach this part, this means we have a list of two or more nodes.
		auto temp = tail;			// have temp look at teh tail for reassignment of tail
		tail = tail->get_prev();	// tail looks at the prev node now and is reassigned
		tail->set_next(nullptr);	// because the back node is being deleted, the next node tail is now looking at has to point to nullptr
		delete temp;				// delete the node temp was looking at, which was at the back
		--dSize;					// decrement size
	}

	template<class T>
	void dstack_list<T>::print_stack()
	{
		std::cout << "bottom | ";
		auto curr = head;
		while (curr != nullptr)
		{
			std::cout << curr->get_data() << " | ";
			curr = curr->get_next();
		}
		std::cout << " top.\n";
	}
}// namespace drw
