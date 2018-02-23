// Andrew Esberto
// first attempt to recreate the vector class
// cans :	look at http://www.cplusplus.com/reference/vector/vector/ for reference
//			check for syntax things that I don't remember
//			use google for C++ things but not actual implementations of API
//
// can'ts:	look up actual implementations of API
//			use any STL that's not made by me
//			use bing
//			not eat pizza

#ifndef DVECTOR_H
#define DVECTOR_H

namespace drw
{
	template<typename T>
	class dvector
	{
	public:
		dvector();
		~dvector();
			
		// CAPACITY
		int size() const;
		//int max_size() const;
		void resize(int);
		int capacity() const;
		bool empty() const;
		void reserve(int);
		
		// ELEMENT ACCESS
		T &operator[](int) const;
		//T at(int) const;
		//T front() const;
		//T back() const;
		//T data();
			
		// MODIFIERS
		//void assign(int, T);
		void push_back(const T);
		void pop_back();
		//void insert();
		//void erase();
		//void swap();
		//void clear();

	
	private:
		T *arr;			// short of array. used to be the container for dvector
		int dSize; 		// number of elements living in container.
		int dCapacity;	// number of available space in container or current container size. grows in powers of 2.
		
	};// class - dvector ---- my attempt to recreate the implementation of c++'s vector class.
}// namespace - drw

#endif // DVECTOR_H