#include "dvector.h"
#include <iostream> // for debugging

namespace drw
{
	// default constructor for creating dvector.
	// container is just empty
	template<class T>
	dvector<T>::dvector() 
		: arr(nullptr), dSize(0), dCapacity(1)
	{
		arr = new T[dSize];
	}

	// initialize the size of the container. 
	// zeroes will be filled in the container
	template<class T>
	dvector<T>::dvector(const int size)
		: arr(nullptr) , dSize(size)
	{
		dCapacity = size == 0 ? 1 : size;
		arr = new T[dSize];
		for (int i = 0; i < dSize; ++i) arr[i] = 0; // fill arr with 0's 
	}

	// initialize the size of the container.
	// and fill container with a value
	template<class T>
	dvector<T>::dvector(const int size, const T val)
		: arr(nullptr), dSize(size)
	{
		dCapacity = size == 0 ? 1 : size;
		arr = new T[dSize];
		for (int i = 0; i < dSize; ++i) arr[i] = val;
	}

	// copys the passed in dvector
	template<class T>
	dvector<T>::dvector(dvector<T> &copyArr)
		:arr(nullptr)
	{
		operator=(copyArr);
	}

	// destructor - memory gets free'd or somethin'
	// deletes arr and for saftey measures, sets arr to nullptr
	template<class T>
	dvector<T>::~dvector()
	{
		delete[]arr;
		arr = nullptr;
	}

	// sets arr equal to copy the copyArr
	// will delete current container if it is already set to something
	template<class T>
	dvector<T> & dvector<T>::operator=(const dvector<T> &copyArr)
	{
		if (arr != nullptr)
		{
			delete[] arr;
			arr = nullptr;
		}

		dSize = copyArr.size();
		dCapacity = copyArr.capacity();
		arr = new T[dCapacity];

		for (int i = 0; i < dSize; ++i) arr[i] = copyArr[i]; // copy contents of copyArr into arr

		return *this; // i cheated at this part
	}

	 ////////////////////////////////////////////////
	 /////////////	     CAPACITY       ////////////
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
		if (newSize > dCapacity) reserve(resizeCapacity());
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
		return dSize == 0 ? true : false;
	}

	// allocation of memory will occur if current size is less than passed in value. 
	// increases dCapacity. 
	// kind of cheated at this part by accident. O.o
	template<class T>
	void dvector<T>::reserve(const int newCapacity)
	{
		if (newCapacity < dSize) return; // if reserve's less than what's already available, skip

		T *oldArr = arr;				// hold copy of old array 
		arr = new T[newCapacity];		// create a new arr with new capacity
		for (int i = 0; i < dSize; ++i) arr[i] = oldArr[i];	// copy elements in newly sized arr

		dCapacity = newCapacity;
		delete[] oldArr;
	}

	// reallocates memory. copies elements into a new arr temporarily. 
	// the dCapacity will be equal dSize.
	template<class T>
	void dvector<T>::shrink_to_fit()
	{
		T *oldArr = arr;
		arr = new T[dSize];
		for (int i = 0; i < dSize; ++i) arr[i] = oldArr[i];

		dCapacity = dSize == 0 ? 1 : dSize;
		delete[] oldArr;
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

	// returns first element
	template<class T>
	T dvector<T>::front() const
	{
		return T[0];
	}

	// returns last element
	template<class T>
	T dvector<T>::back() const
	{
		return T[dSize - 1];
	}


	////////////////////////////////////////////////
	/////////////	    MODIFIERS       ////////////
	////////////////////////////////////////////////

	// adds element to container at the end. increments dSize.
	// will resize dCapacity if dSize + 1 >= dCapacity
	// memory allocation will occur if needed
	template<class T>
	void dvector<T>::push_back(const T element)
	{
		if (dSize + 1 >= dCapacity)
		{
			reserve(resizeCapacity());
		}

		arr[dSize] = element;	// put new element at end of arr 
		++dSize;
	}

	// deletes last element. decrements dSize.
	// does not free up any memory when deleting elements.
	template<class T>
	void dvector<T>::pop_back()
	{
		arr[dSize] = 0;						// deletes last element by naking it zero
		dSize = dSize == 0 ? 0 : dSize - 1;	// if 0, keep it 0, else decrement dSize.
	}

	// clears elements in arr. 
	// i just learned that this DOES NOT free up memory or change dCapacity.
	// to free up memory, use shrink_to_fit(int).
	// this is so it will make pushing in new elements more efficient that when
	// it had to resize due to having a small capacity.
	template<class T>
	void dvector<T>::clear()
	{
		for (int i = dSize; i > 0; --i) pop_back();
	}

	// returns value of what capacity should be resized to. mainly checks if it is zero. 
	// then after that grows in powers of 2, unless shrink_to_fit is called. 
	// then it grows by dSize * 2 or something
	template<class T>
	unsigned int dvector<T>::resizeCapacity()
	{
		return dCapacity * 2;
	}

}// namespace drw