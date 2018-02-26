#include "stdafx.h"		// for visual studio
#include "dvector.h"
#include <iostream>		// for debugging

namespace drw
{
	// default constructor for creating dvector.
	// container is just empty
	template<class T>
	dvector<T>::dvector() 
		: dSize(0), dCapacity(1)
	{
		arr = std::unique_ptr<T[]>(new T[dSize]);
	}

	// initialize the size of the container. 
	// zeroes will be filled in the container
	template<class T>
	dvector<T>::dvector(const int size)
		: dSize(size)
	{
		dCapacity = size == 0 ? 1 : size;
		arr = std::unique_ptr<T[]>(new T[dSize]);
		for (int i = 0; i < dSize; ++i) arr[i] = static_cast<T>(0); // fill arr with 0's 
	}

	// initialize the size of the container.
	// and fill container with a value
	template<class T>
	dvector<T>::dvector(const int size, const T val)
		: dSize(size)
	{
		dCapacity = size == 0 ? 1 : size;
		arr = std::unique_ptr<T[]>(new T[dSize]);
		for (int i = 0; i < dSize; ++i) arr[i] = val;
	}

	// copys the passed in dvector
	template<class T>
	dvector<T>::dvector(dvector<T> &copyArr)
		: arr(nullptr)
	{
		operator=(copyArr);
	}

	// destructor - memory gets free'd or somethin'
	// deletes automatically arr and for saftey measures, sets arr to nullptr
	template<class T>
	dvector<T>::~dvector()
	{
		arr = nullptr;
	}

	// sets arr equal to copy the copyArr
	// will delete current container if it is already set to something
	template<class T>
	dvector<T> & dvector<T>::operator=(const dvector<T> &copyArr)
	{
		if (arr != nullptr) arr = nullptr;

		dSize = copyArr.size();
		dCapacity = copyArr.capacity();
		arr = std::unique_ptr<T[]>(new T[dCapacity]);

		for (int i = 0; i < dSize; ++i) arr[i] = copyArr[i]; // copy contents of copyArr into arr

		return *this; // i cheated at this part
	}


	/////////////////////////////////////////////////
	/////////////	     ITERATORS       ////////////
	/////////////////////////////////////////////////







	 ////////////////////////////////////////////////
	 /////////////	     CAPACITY       /////////////
	 ////////////////////////////////////////////////

	 // return size of container or number of elements in container.
	template<class T>
	int dvector<T>::size() const
	{
		return dSize;
	}

	//int template <class T> dvector<T>::max_size(){}

	// resizes the container. 
	// calls on reserve(int) if passed in value is greater than the current capacity.
	// allocation of memory may occur
	template<class T>
	void dvector<T>::resize(const unsigned int newSize)
	{
		if (newSize > dCapacity) reserve(dCapacity * 2);
		dSize = newSize;
	}

	// returns capacity of container
	template<class T>
	unsigned int dvector<T>::capacity() const
	{
		return dCapacity;
	}

	// if size is greater than 0, return false. else return true.
	template<class T>
	bool dvector<T>::empty() const
	{
		return dSize == 0;
	}

	// allocation of memory will occur if current size is less than passed in value. 
	// increases dCapacity. 
	// kind of cheated at this part by accident. O.o
	template<class T>
	void dvector<T>::reserve(const int newCapacity)
	{
		if (newCapacity < dSize) return; // if reserve's less than what's already available, skip

		auto oldArr(std::move(arr));						// hold copy of old array 
		arr = std::unique_ptr<T[]>(new T[newCapacity]);		// create a new arr with new capacity
		for (int i = 0; i < dSize; ++i) arr[i] = oldArr[i];	// copy elements in newly sized arr

		dCapacity = newCapacity;
	}

	// deallocates memory. copies elements into a new arr temporarily. 
	// the dCapacity will be equal dSize.
	template<class T>
	void dvector<T>::shrink_to_fit()
	{
		auto oldArr(std::move(arr));
		arr = std::unique_ptr<T[]>(new T[dSize]);
		for (int i = 0; i < dSize; ++i) arr[i] = oldArr[i];

		dCapacity = dSize == 0 ? 1 : dSize;
	}

	////////////////////////////////////////////////
	/////////////	 ELEMENT ACCESS	    ////////////
	////////////////////////////////////////////////

	// access element like an array
	// should i check if what they're accessing is possibly out of range?
	template<class T>
	T dvector<T>::operator[](const unsigned int index) const
	{
		return arr[index];
	}

	// returns reference of first element
	template<class T>
	T* dvector<T>::front() const
	{
		return &arr[0];
	}

	// returns reference of last element
	template<class T>
	T* dvector<T>::back() const
	{
		return &arr[dSize - 1];
	}

	////////////////////////////////////////////////
	/////////////	    MODIFIERS       ////////////
	////////////////////////////////////////////////

	// adds element to container at the end. increments dSize.
	// will resize dCapacity if dSize + 1 >= dCapacity
	// memory allocation will occur if needed
	template<class T>
	void dvector<T>::push_back(const T& element)
	{
		if (dSize + 1 >= dCapacity)
		{
			reserve(dCapacity * 2);
		}

		arr[dSize] = element;	// put new element at end of arr 
		++dSize;
	}

	// decrements dSize. "deleting" element isn't really necessary
	// does not free up any memory when deleting elements.
	template<class T>
	void dvector<T>::pop_back()
	{
		dSize = dSize == 0 ? 0 : dSize - 1;	// if 0, keep it 0, else decrement dSize.
	}

	// "clears" elements in arr. values are still there but they aren't within reaching bounds anymore.
	// i just learned that this DOES NOT free up memory or change dCapacity.
	// to free up memory, use shrink_to_fit(int).
	// this is so it will make pushing in new elements more efficient that when
	// it had to resize due to having a small capacity.
	template<class T>
	void dvector<T>::clear()
	{
		dSize = 0;
	}

}// namespace drw