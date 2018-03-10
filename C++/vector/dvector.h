// Andrew Esberto
// first attempt to recreate the vector class mainly 4 lurningz
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

#include <cstddef>
#include <memory>
#include <initializer_list>

namespace drw
{
	template<class T>
	class dvector
	{
	public:
		explicit dvector();
		explicit dvector(const std::size_t);
		explicit dvector(const std::size_t, const T);
		dvector(std::initializer_list<T>);
		dvector(dvector<T>&);
		~dvector();
		dvector<T> &operator=(const dvector<T>&);

		// ITERATORS - actually, I won't be making iterators to make my life harder.
		// I'm also not going to use this class longterm, so no point.

		// CAPACITY
		std::size_t size() const;
		//int max_size() const;
		void resize(const std::size_t);
		std::size_t capacity() const;
		bool empty() const;
		void reserve(const std::size_t);
		void shrink_to_fit();

		// ELEMENT ACCESS
		T operator[](const std::size_t) const;
		//T at(int) const;
		T &front() const;
		T &back() const;
		//T data();

		// MODIFIERS
		//void assign(int, T);
		void push_back(const T&);
		void pop_back();
		//void insert();
		//void erase();
		//void swap();
		void clear();


	private:
		std::unique_ptr<T[]> arr;	// unique_ptr to hold array
		std::size_t dSize; 				// number of elements living in container.
		std::size_t dCapacity;		// number of available space in container or current container size. grows in powers of 2.

	};// class - dvector ---- my attempt to recreate the implementation of c++'s vector class.
}// namespace - drw
#endif // DVECTOR_H
