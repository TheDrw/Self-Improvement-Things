#include "stdafx.h"
#include "queue_singly_list.h"

namespace drw
{
	// default constructor
	template<class T>
	queue_singly_list<T>::queue_singly_list()
		:dSize(0), head(nullptr), tail(nullptr)
	{}

	// start queue with one item in
	template<class T>
	queue_singly_list<T>::queue_singly_list(const T &data)
		: dSize(0), head(nullptr), tail(nullptr)
	{
		push(data);
	}

	// DESTROY ALL
	template<class T>
	queue_singly_list<T>::~queue_singly_list()
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

	// return if queue is empty
	template<class T>
	bool queue_singly_list<T>::empty()
	{
		return dSize == 0;
	}

	// return size of list
	template<class T>
	std::size_t queue_singly_list<T>::size() const
	{
		return dSize;
	}

	// return element at front of queue
	template<class T>
	T queue_singly_list<T>::front() const
	{
		return head->get_data();
	}

	// return eleemnt at back of queue
	template<class T>
	T queue_singly_list<T>::back() const
	{
		return tail->get_data();
	}

	// push item to the back of queue. allocates memory and increments size
	template<class T>
	void queue_singly_list<T>::push(const T &data)
	{
		auto new_node = new dnode<T>(data);

		// if empty list, have head and tail point at new_node
		// else put item at the tail
		if (empty())
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->set_next(new_node);
			tail = new_node;
		}

		++dSize;
	}

	// pop item at the front of queue. deallocates memory and decrements size.
	template<class T>
	void queue_singly_list<T>::pop()
	{
		if (empty()) return;

		auto temp = head;
		head = head->get_next();
		delete temp;

		--dSize;
	}

	// prints queue
	template<class T>
	void queue_singly_list<T>::print_queue()
	{
		std::cout << "front | ";
		auto curr = head;
		while (curr != nullptr)
		{
			std::cout << curr->get_data() << " | ";
			curr = curr->get_next();
		}
		std::cout << " back.\n";
	}
}// namespace - drw
