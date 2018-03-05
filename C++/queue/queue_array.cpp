#include "stdafx.h"
#include "queue_array.h"


namespace drw
{
	template<class T>
	queue_array<T>::queue_array()
		:dSize(0), dCapacity(4), dFront(1), dBack(1)
	{
		dFront = 1;
		dBack = 1;
		dArray = std::unique_ptr<T[]>(new T[dCapacity]);
	}

	template<class T>
	queue_array<T>::queue_array(const T &data)
		:dSize(0), dCapacity(4), dFront(1), dBack(1)
	{
		dArray = std::unique_ptr<T[]>(new T[dCapacity]);
		push(data);
	}

	template<class T>
	queue_array<T>::~queue_array()
	{
		// smart pointer b smart and duz thingz 4 me.
	}

	template<class T>
	bool queue_array<T>::empty()
	{
		return dSize == 0;
	}

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

	// enqueue
	template<class T>
	void queue_array<T>::push(const T& data)
	{
		//std::cout << "pushing : " << data << "\n";
		dArray[dBack] = data;
		++dSize;

		// if size reaches capacity, dCapacity will double in size
		if (dSize == dCapacity)	grow();

		dBack = (dBack + 1) % dCapacity;	// if dCapcity doubles, having it here will effect the circular thing
	}

	// dequeue
	template<class T>
	void queue_array<T>::pop()
	{
		if (empty()) return;

		//std::cout << "popping: " << front() << " \n";
		
		--dSize;

		// TODO : SHRINK DUZ NAUGHT WURK! T_T
		//const int INITIAL_CAPACITY = 4;
		// if (dCapacity == dSize * INITIAL_CAPACITY && dCapacity != INITIAL_CAPACITY) shrink();
		

		dFront = (dFront + 1) % dCapacity;
	}

	template<class T>
	void queue_array<T>::print_queue()
	{
		std::cout << "queue : ";
		for(std::size_t i = 0; i < dSize; ++i)
		{
			std::size_t index = (dFront + i) % dCapacity;
			std::cout << dArray[index] << " | ";
		}
		std::cout << " .\n";
		print_array();
	}

	template<class T>
	void queue_array<T>::print_array()
	{
		std::cout << "array : ";
		for (std::size_t i = 0; i < dCapacity; ++i)
		{
			std::cout << dArray[i] << " | ";
		}
		std::cout << " .\n";
		std::cout << "front : " << dFront << "  back: " << dBack <<  " size: " << dSize <<  " cap: " << dCapacity << "\n\n";
	}

	template<class T>
	void queue_array<T>::grow()
	{
		std::size_t oldCapacity = dCapacity;				// remember old capacity
		dCapacity *= 2;										// double cap
		auto oldArray(std::move(dArray));					// temp store old array
		dArray = std::unique_ptr<T[]>(new T[dCapacity]);	// new resized array
		std::size_t newArrayIndex = 0;						// used to put set the new dBack index after transfer
		for (std::size_t i = 0; i < dSize; ++i)
		{
			std::size_t oldArrayIndex = (dFront + i) % oldCapacity;
			newArrayIndex = (dFront + i) % dCapacity;

			dArray[newArrayIndex] = oldArray[oldArrayIndex];
		}
		dBack = newArrayIndex;								// translate the old back position to this new one
	}

	// TODO : fix it
	template<class T>
	void queue_array<T>::shrink()
	{
		std::cout <<  "BEFORE SHIRNK--------\n";
		print_queue();


		std::size_t oldCapacity = dCapacity;
		dCapacity /= 2;
		auto oldArray(std::move(dArray));
		dArray = std::unique_ptr<T[]>(new T[dCapacity]);
		std::size_t newArrayIndex = 0;
		//std::size_t temp = dFront % dCapacity;
		for (std::size_t i = 0; i < dSize; ++i)
		{
			std::size_t oldArrayIndex = (dFront + i) % oldCapacity;
			newArrayIndex = (dFront + i) % dCapacity;

			dArray[newArrayIndex] = oldArray[oldArrayIndex];
		}
		//dFront = temp;
		dBack = newArrayIndex;

		std::cout << "AFTER SHRINK ------- \n";
		print_queue();
	}
}// namespace - drw
