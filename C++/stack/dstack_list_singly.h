// Andrew Esberto
// first attempt to recreate the stack class mainly 4 lurningz
// To make it more interesting, I'll be implementing stack as a array and list
// This is fairly trivial and is pretty much just a forward linked list but the way I think about it, is it's backwards.
// Instead of bringing the dnode class from lists, i'll just put it in the header and avoid linking issues and changing things.
// cans :	look at http://www.cplusplus.com/reference/stack/stack/ for reference
//			check for syntax things that I don't remember
//			use google for C++ things but not actual implementations of API
//
// can'ts:	look up actual implementations of API
//			use any STL that's not made by me unless it is too hard 
//			use bing
//			not eat pizza

#ifndef DSTACK_LIST_SINGLY
#define DSTACK_LIST_SINGLY

namespace drw
{
	template<class T>
	class dstack_list_singly
	{
	public:
		explicit dstack_list_singly();
		explicit dstack_list_singly(const T&);
		~dstack_list_singly();

		// member functions
		bool empty();
		std::size_t size() const;
		T top() const;
		void push(const T&);
		//emplace
		void pop();
		//swap

		// extras
		void print_stack();
	private:

		// because this is a stack, the "next" node should really be called previous
		// this is because items are pushed onto the top. 
		// so the next item up should be before the item on the top.
		// i just had trouble visualizing it at first, 
		// so if someone else out there also has trouble, i hope i made it worse.
		// or made it better! :D
		template<class T>
		class dnode
		{
		public:
			dnode(const T&d)
				:prev(nullptr), data(d){}
			~dnode() {}

			// SETTERS
			void set_prev(dnode<T>* prev_node) { prev = prev_node; }

			// GETTERS
			dnode<T> *get_prev() { return prev; }
			T get_data() const { return data; }

		private:
			T data;
			dnode<T> *prev;
		};// class dnode

		dnode<T> *head;
		std::size_t dSize;
	};// class dstack_list_singly
}// namespace drw
#endif