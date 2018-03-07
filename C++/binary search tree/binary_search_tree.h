// Andrew Esberto
// first attempt to create a binary search tree.
// I've never used a binary search tree, so this may take a while. but I understand the concept of its implementation.
// my recursion skills is fairly poor, so I am hoping this may improve it.
// this utilizes smart pointers
// cans :	look at https://github.com/jwasham/practice-cpp/tree/master/binary_search_tree (only looking at .h),
//			page 126 in Data Structures and Algorithms in C++ 3rd Edition by Mark Allen Weiss for reference,
//			and https://codereview.stackexchange.com/questions/51111/binary-tree-with-c11-smart-pointers (looking at the smart pointers usage)
//			check for syntax things that I don't remember
//			use google for C++ things but not actual implementations of API
//
// can'ts:	look up actual implementations of API
//			use any STL that's not made by me unless it is too hard 
//			use bing
//			not eat pizza

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <cstddef>
#include <memory>
#include <iostream>

namespace drw
{
	template<class T>
	class binary_search_tree
	{
	private:
		struct binary_node;
		typedef std::unique_ptr<binary_node> node_ptr;
		// node for the binary search tree. placed here for convienience
		struct binary_node
		{
			binary_node() : data(d), left(), right() {}
			binary_node(const T& d) : data(d), left(), right() {}

			T data;
			node_ptr left;
			node_ptr right;
		};

	public:
		explicit binary_search_tree();
		explicit binary_search_tree(const binary_search_tree &);
		explicit binary_search_tree(binary_search_tree &&);
		~binary_search_tree();
		binary_search_tree &operator=(const binary_search_tree &);
		binary_search_tree &operator=( binary_search_tree &&);

		// CAPACITY
		bool contains(const T&) ;
		bool empty() const;
		std::size_t size() const;

		// ELEMENT ACCESS
		const T& find_min() const;
		const T& find_max() const;

		// MODIFIERS
		void insert(const T&);
		void remove(const T&);
		void make_empty();
		
		//node_ptr clone(node_ptr) const;

		// EXTRAS
		void print_tree() ;

	private:
		bool contains(const T&, node_ptr&) ;
		void insert(const T&, node_ptr&) const;
		void remove(const T&, node_ptr&) const;
		

		node_ptr find_min(node_ptr&) const;
		node_ptr find_max(node_ptr&) const;

		void make_empty(node_ptr&);
		void print_tree(node_ptr&) const;

	private:
		node_ptr root;
		std::size_t node_count;
	};

	// class binary_search_tree
}// namespace drw
#endif // BINARY_SEARCH_TREES
