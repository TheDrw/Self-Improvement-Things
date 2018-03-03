#include "stdafx.h"
#include "dstack_list_singly.h"

namespace drw
{
	// default constructor
	template<class T>
	dstack_list_singly<T>::dstack_list_singly()
		:head(nullptr), dSize(0)
	{}
	
	// constructor to add on one new item
	template<class T>
	dstack_list_singly<T>::dstack_list_singly(const T &data)
		: head(nullptr), dSize(0)
	{
		push(data);
	}

	// deletes list. deallocation of memory occurs
	template<class T>
	dstack_list_singly<T>::~dstack_list_singly()
	{
		auto curr = head;
		while (curr != nullptr)
		{
			auto temp = curr;
			curr = curr->get_prev();
			delete temp;
		}
	}

	////////////////////////////////////////////////
	/////////////	 MEMBER FUNCTIONS    ///////////
	////////////////////////////////////////////////

	// returns if list is empty
	template<class T>
	bool dstack_list_singly<T>::empty()
	{
		return dSize == 0;
	}

	// returns size of list
	template<class T>
	std::size_t dstack_list_singly<T>::size() const
	{
		return dSize;
	}

	// returns item on top stack
	// crashes if list is empty
	template<class T>
	T dstack_list_singly<T>::top() const
	{
		return head->get_data();
	}

	// push item onto stack. allocates memory and increments size.
	template<class T>
	void dstack_list_singly<T>::push(const T &data)
	{
		auto new_node = new dnode<T>(data);
		new_node->set_prev(head);
		head = new_node;

		++dSize;
	}

	// pops item off stack. deallocates memory and decrements size.
	template<class T>
	void dstack_list_singly<T>::pop()
	{
		if (empty()) return;
		auto temp = head;
		head = head->get_prev();
		delete temp;

		--dSize;
	}

	// prints out stack in reverse
	template<class T>
	void dstack_list_singly<T>::print_stack()
	{
		std::cout << "size: " << dSize <<  " **** top | ";
		auto curr = head;
		while (curr != nullptr)
		{
			std::cout << curr->get_data() << " | ";
			curr = curr->get_prev();
		}
		std::cout << " bottom.\n";
	}
}