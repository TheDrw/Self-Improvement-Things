#include "dvector.h"

namespace drw
{
	// default constructor for creating dvector.
	// container is just empty
	template<class T>
	dvector<T>::dvector() 
		: dSize(0), dCapacity(1)
	{
		arr = std::make_unique<T[]>(dSize);
	}

	// initialize the size of the container. 
	// zeroes will be filled in the container
	template<class T>
	dvector<T>::dvector(const std::size_t s)
		: dSize(s)
	{
		dCapacity = s == 0 ? 1 : s;
		arr = std::make_unique<T[]>(dSize);
		for (std::size_t i = 0; i < dSize; ++i) arr[i] = static_cast<T>(0); // fill arr with 0's 
	}

	// initialize the size of the container.
	// and fill container with a value
	template<class T>
	dvector<T>::dvector(const std::size_t s, const T val)
		: dSize(s)
	{
		dCapacity = s == 0 ? 1 : s;
		arr = std::make_unique<T[]>(dSize);
		for (std::size_t i = 0; i < dSize; ++i) arr[i] = val;
	}

	template<class T>
	dvector<T>::dvector(std::initializer_list<T> i_list)
		: dSize(0), dCapacity(1)
	{
		arr = std::make_unique<T[]>(dSize);
		for (const auto& element : i_list)	push_back(element);
	}

	// copys the passed in dvector
	template<class T>
	dvector<T>::dvector(dvector<T> &copyArr)
	{
		operator=(copyArr);
	}

	// destructor - memory gets free'd or somethin'
	// deletes automatically arr
	template<class T>
	dvector<T>::~dvector()
	{}

	// sets arr equal to copy the copyArr
	// will delete current container if it is already set to something
	template<class T>
	dvector<T> & dvector<T>::operator=(const dvector<T> &copyArr)
	{
		if (arr != nullptr) arr = nullptr;

		dSize = copyArr.size();
		dCapacity = copyArr.capacity();
		arr = std::make_unique<T[]>(dCapacity);

		for (std::size_t i = 0; i < dSize; ++i) arr[i] = copyArr[i]; // copy contents of copyArr into arr

		return *this; // i cheated at this part
	}

	 ////////////////////////////////////////////////
	 /////////////	     CAPACITY       /////////////
	 ////////////////////////////////////////////////

	 // return size of container or number of elements in container.
	template<class T>
	std::size_t dvector<T>::size() const
	{
		return dSize;
	}

	//int template <class T> dvector<T>::max_size(){}

	// resizes the container. 
	// calls on reserve if passed in value is greater than the current capacity.
	// allocation of memory may occur
	template<class T>
	void dvector<T>::resize(const std::size_t newSize)
	{
		if (newSize > dCapacity) reserve(dCapacity * 2);
		dSize = newSize;
	}

	// returns capacity of container
	template<class T>
	std::size_t dvector<T>::capacity() const
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
	void dvector<T>::reserve(const std::size_t newCapacity)
	{
		if (newCapacity < dSize) return; // if reserve's less than what's already available, skip

		auto oldArr(std::move(arr));								// oldArr takes ownership of current array. arr has nothing now
		arr = std::make_unique<T[]>(newCapacity);		// create a new arr with new capacity
		for (std::size_t i = 0; i < dSize; ++i) arr[i] = oldArr[i];	// copy elements in newly sized arr

		dCapacity = newCapacity;
	}

	// deallocates memory. copies elements into a new arr temporarily. 
	// the dCapacity will be equal dSize.
	template<class T>
	void dvector<T>::shrink_to_fit()
	{
		auto oldArr(std::move(arr));
		arr = std::make_unique<T[]>(dSize);
		for (std::size_t i = 0; i < dSize; ++i) arr[i] = oldArr[i];

		dCapacity = dSize == 0 ? 1 : dSize;
	}

	////////////////////////////////////////////////
	/////////////	 ELEMENT ACCESS	    ////////////
	////////////////////////////////////////////////

	// access element like an array
	// should i check if what they're accessing is possibly out of range?
	template<class T>
	T dvector<T>::operator[](const std::size_t index) const
	{
		return arr[index];
	}

	// returns reference of first element
	template<class T>
	T &dvector<T>::front() const
	{
		return arr[0];
	}

	// returns reference of last element
	template<class T>
	T &dvector<T>::back() const
	{
		return arr[dSize - 1];
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
