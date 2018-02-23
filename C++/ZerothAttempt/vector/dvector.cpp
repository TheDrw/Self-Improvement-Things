#include "dvector.h"

namespace drw
{

	template<typename T> dvector<T>::dvector() : dSize(0), dCapacity(0)
	{
		arr = new T[dSize];
	}// dvector()
	
	template<typename T> dvector<T>::~dvector()
	{
		delete []arr;
		arr = NULL;
	}// ~dvector
	
	
	////////////////////////////////////////////////
	/////////////		CAPACITY		////////////
	////////////////////////////////////////////////
	
	// return size of container or number of elements in container.
	int template <typename T> dvector<T>::size(){ return dSize; }	

	//int template <typename T> dvector<T>::max_size(){}
	
	// resizes the container. 
	// capacity grows in powers of 2. resizes when size == capacity/2
	void template <typename T> dvector<T>::resize(int newSize)
	{
		if(newSize > dCapacity) reserve(dCapacity * 2 + 1);
		dSize = newSize;
	}
	
	// returns capacity of container
	int template<typename T> dvector<T>::capacity(){ return dCapacity; }

	// if size is greater than 0, return false. else return true.
	bool template<typename T> dvector<T>::empty(){ return dSize > 0 ? false : true; }
	
	// allocate more space in container if needed. increases dCapacity. kind of cheated at this part.
	void template <typename T> dvector<T>::reserve(int newCapacity)
	{	
		if(newCapacity < dSize) return; // if reserves less than what's already available, skip
	
		T *oldArr = arr;				// hold copy of old array 
		arr = new T[newCapacity];		// create a new arr with new capacity
		for(int i = 0; i < dSize; ++i) arr[i] = oldArr[i];	// copy elements in newly sized arr
		
		dCapacity = newCapacity;
		delete []oldArr
	}
	
	////////////////////////////////////////////////
	/////////////	 ELEMENT ACCESS		////////////
	////////////////////////////////////////////////
	
	T template<typename T> dvector<T>::&operator[](int index) { return arr[index] != NULL ? arr[index] : NULL; }
		
	
	////////////////////////////////////////////////
	/////////////		MODIFIERS		////////////
	////////////////////////////////////////////////
	
	// adds element to container at the end. increments dSize.
	void template<typename T> dvector<T>::push_back(const T)
	{
		if(dSize + 1 > dCapacity) reserve(dCapacity * 2 + 1);
		
		++dSize;
		arr[dSize] = T;	// put new element at end of arr 
	}
	
	// deletes last element. decrements dSize.
	void template<typename T> dvector<T>::pop_back()
	{
		arr[dSize] = 0;						// deletes last element by naking it zero
		dSize = dSize == 0 ? 0 : dSize - 1;	// if 0, keep it 0, else decrement dSize.
	}
	
	
}// namespace drw