#include "dstack_array.h"

namespace drw
{
	// default constructor
	// magic number 0 is starting size.
	// magic number 4 is the starting capacity.
	template<class T>
	dstack_array<T>::dstack_array()
		:dSize(0), dCapacity(4)
	{
		arr = std::make_unique<T[]>(dCapacity);
	}

	// initialize stack with one item on the stack
	template<class T>
	dstack_array<T>::dstack_array(const T &data)
		:dSize(0), dCapacity(4)
	{
		arr = std::make_unique<T[]>(dCapacity);
		push(data);
	}

	template<class T>
	dstack_array<T>::dstack_array(std::initializer_list<T> i_list)
		:dSize(0), dCapacity(4)
	{
		arr = std::make_unique<T[]>(dCapacity);
		for(const auto &element : i_list) push(element);
	}
	
	template<class T>
	dstack_array<T>::~dstack_array()
	{}

	////////////////////////////////////////////////
	/////////////	 MEMBER FUNCTIONS    /////////////
	////////////////////////////////////////////////

	// checks if stack is empty
	template<class T>
	bool dstack_array<T>::empty()
	{
		return dSize == 0;
	}

	// returns the size of the stack
	template<class T>
	std::size_t dstack_array<T>::size() const
	{
		return dSize;
	}

	// returns the item on the top of the stack
	template<class T>
	T &dstack_array<T>::top() const
	{
		return arr[dSize - 1];
	}

	// push an item onto the top of the stack.
	// this pushed item becomes the new top.
	// allocation of memory may occur
	template<class T>
	void dstack_array<T>::push(const T &data)
	{
		if (dSize + 1 == dCapacity) grow();

		arr[dSize] = data;
		++dSize;
	}

	// delete the top item on the stack.
	// deallocation of memory may occur
	template<class T>
	void dstack_array<T>::pop()
	{
		if (empty()) return;

		const std::size_t INITIAL_CAPACITY = 4;
		if (dCapacity == dSize * INITIAL_CAPACITY && dCapacity != INITIAL_CAPACITY) shrink();

		--dSize;
	}

	// print stack. just for debugging stuff
	template<class T>
	void dstack_array<T>::print_stack()
	{
		std::cout << "bottom | ";
		for (std::size_t i = 0; i < dSize; ++i)
		{
			std::cout << arr[i] << " | ";
		}
		std::cout << " top.\n";
	}

	///////////////////////// private functions

	// used to double capacity of array when size meets capacity.
	// allocation of memory will occur
	template<class T>
	void dstack_array<T>::grow()
	{
		dCapacity *= 2;	// double size of capacity
		std::cout << "new size: " << dCapacity << "\n";
		resizeArr();
	}

	// used to shrink the array by half when the size is 1/4th the capacity
	// deallocation of memory will occur
	template<class T>
	void dstack_array<T>::shrink()
	{
		dCapacity /= 2;
		std::cout << "new size: " << dCapacity << "\n";
		resizeArr();
	}

	// used to for grow() and shrink(). 
	// it just resizes the array accordingly.
	template<class T>
	void dstack_array<T>::resizeArr()
	{
		auto oldArr(std::move(arr));
		arr = std::make_unique<T[]>(dCapacity);
		for (std::size_t i = 0; i < dSize; ++i) arr[i] = oldArr[i];
	}
	
}
