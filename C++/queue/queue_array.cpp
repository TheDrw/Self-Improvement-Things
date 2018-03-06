// Andrew Esberto
#include "stdafx.h"
#include "queue_array.h"

namespace drw
{
	template<class T>
	queue_array<T>::queue_array()
		:dSize(0), dCapacity(4), dFront(0), dBack(0)
	{
		dArray = std::unique_ptr<T[]>(new T[dCapacity]);
	}

	template<class T>
	queue_array<T>::queue_array(const T &data)
		:dSize(0), dCapacity(4), dFront(0), dBack(0)
	{
		dArray = std::unique_ptr<T[]>(new T[dCapacity]);
		push(data);
	}

	template<class T>
	queue_array<T>::~queue_array()
	{
		// smart pointer b smart and duz thingz 4 me.
	}

	// returns true if queue is empty
	template<class T>
	bool queue_array<T>::empty()
	{
		return dSize == 0;
	}

	// return current size of queue.
	template<class T>
	std::size_t queue_array<T>::size() const
	{
		return dSize;
	}

	// get first element in queue by reference
	template<class T>
	T& queue_array<T>::front() const
	{
		return dArray[dFront];
	}

	// get last element in queue by reference
	template<class T>
	T& queue_array<T>::back() const
	{
		return dArray[dBack];
	}

	// enqueue - insert element to the back of the queue.
	// increments size and possible memory allocation occurs.
	// the queue will grow if the we all spots are taken in the array.
	template<class T>
	void queue_array<T>::push(const T& data)
	{
		dArray[dBack] = data;
		++dSize;

		// if size reaches capacity, dCapacity will double in size
		// else move dBack up
		if (dSize == dCapacity)
		{
			grow();
		}
		else
		{
			dBack = (dBack + 1) % dCapacity;
		}
	}

	// dequeue - pop front element in the queue.
	// if queue is empty, nothing happens.
	// decrements size and possible memory deallocation occurs.
	// the queue will 1/2 in size if 1/4th of the capacity is being used.
	// and this will only occur if capacity != 4.
	template<class T>
	void queue_array<T>::pop()
	{
		if (empty()) return;

		--dSize;

		const int THRESHOLD_CAPACITY = 4;
		if (dCapacity == dSize * THRESHOLD_CAPACITY && dCapacity != THRESHOLD_CAPACITY)
		{
			shrink();
		}
		else
		{
			dFront = (dFront + 1) % dCapacity;
		}
	}

	// prints queue
	template<class T>
	void queue_array<T>::print_queue()
	{
		std::cout << "queue : ";
		for (std::size_t i = 0; i < dSize; ++i)
		{
			std::size_t index = (dFront + i) % dCapacity;
			std::cout << dArray[index] << " | ";
		}
		std::cout << " .\n";
		//print_array();
	}

	// prints the array that's used for the queue
	// note: will include garbage values
	template<class T>
	void queue_array<T>::print_array()
	{
		std::cout << "array : ";
		for (std::size_t i = 0; i < dCapacity; ++i)
		{
			std::cout << dArray[i] << " | ";
		}
		std::cout << " .\n";
		std::cout << "front : " << dFront << "  back: " << dBack << " size: " << dSize << " cap: " << dCapacity << "\n\n";
	}

	// grows the array when queue is full.
	// the capacity will double and allocation of memory will occur.
	template<class T>
	void queue_array<T>::grow()
	{
		std::size_t oldCapacity = dCapacity;				// remember old capacity
		dCapacity *= 2;										// double cap
		auto oldArray(std::move(dArray));					// temp store old array
		dArray = std::unique_ptr<T[]>(new T[dCapacity]);	// new resized array

		for (std::size_t i = 0; i < dSize; ++i)
		{
			std::size_t oldArrayIndex = (dFront + i) % oldCapacity;
			dArray[i] = oldArray[oldArrayIndex];
		}
		dFront = 0;
		dBack = dSize;								
	}

	// shrinks array when queue is only occupying 1/4th of the capacity
	// capacity is cut in half and dellocation of memory will occur.
	// function is similar to grow() but in oldArrayIndex, i add 1 in the expression.
	// i added 1 because reading from the array would start 1 behind for some reason. why? ¯\_(ツ)_/¯
	// i wanted to separate it and use the common functionality from grow and shrink but the +1 thing ruins it.
	// mainly because everything is working how it is and if i change that, i'll have to do stuff.
	// unless pizza is involved, i ain't fixing what ain't broke. 
	template<class T>
	void queue_array<T>::shrink()
	{
		std::size_t oldCapacity = dCapacity;				// remember old capacity
		dCapacity /= 2;										// cut capacity in half
		auto oldArray(std::move(dArray));					// temp story old array
		dArray = std::unique_ptr<T[]>(new T[dCapacity]);	// resize curr array

		for (std::size_t i = 0; i < dSize; ++i)
		{
			std::size_t oldArrayIndex = (dFront + i + 1) % oldCapacity;	
			dArray[i] = oldArray[oldArrayIndex];						
		}
		dFront = 0;
		dBack = dSize;
	}
}// namespace - drw