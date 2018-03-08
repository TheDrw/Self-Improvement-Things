// andrew esberto
#include "stdafx.h"
#include "binary_search_tree.h"


namespace drw
{
	template<class T>
	binary_search_tree<T>::binary_search_tree()
		: root(), node_count(0)
	{
	}

	template<class T>
	binary_search_tree<T>::~binary_search_tree()
	{}

	/////////////////////////////////////////////////
	/////////////	     CAPACITY       /////////////
	/////////////////////////////////////////////////

	template<class T>
	const bool binary_search_tree<T>::contains(const T &data)
	{
		return contains(data, root);
	}

	template<class T>
	const bool binary_search_tree<T>::empty() const
	{
		return !root;
	}

	template<class T>
	const std::size_t binary_search_tree<T>::size() const
	{
		return node_count;
	}

	////////////////////////////////////////////////
	/////////////	 ELEMENT ACCESS	    ////////////
	////////////////////////////////////////////////

	template<class T>
	const T &binary_search_tree<T>::find_min() const
	{
		auto temp_ptr = root.get();
		while (temp_ptr->left)	temp_ptr = temp_ptr->left.get();
		return temp_ptr->data;
	}

	template<class T>
	const T &binary_search_tree<T>::find_max() const
	{
		auto temp_ptr = root.get();
		while (temp_ptr->right)	temp_ptr = temp_ptr->right.get();
		return temp_ptr->data;
	}

	template<class T>
	const T &binary_search_tree<T>::find_min_recurse()
	{
		return find_min_recurse(root);
	}

	template<class T>
	const T &binary_search_tree<T>::find_max_recurse()
	{
		return find_max_recurse(root);
	}

	////////////////////////////////////////////////
	/////////////	    MODIFIERS       ////////////
	////////////////////////////////////////////////

	template<class T>
	void binary_search_tree<T>::insert(const T &data)
	{
		++node_count;
		insert(data, root);
	}

	template<class T>
	void binary_search_tree<T>::make_empty()
	{
		root.reset();
	}

	template<class T>
	void binary_search_tree<T>::print_tree()
	{
		print_tree(root);
	}

	//////////////////////////////////////////////////////////////////
	////////////////////  private functions	  ////////////////////////
	//////////////////////////////////////////////////////////////////

	template<class T>
	const bool binary_search_tree<T>::contains(const T &data, node_ptr &node)
	{
		if (!node)
			return false;
		else if (data < node->data)
			return contains(data, node->left);
		else if (data > node->data)
			return contains(data, node->right);
		else
			return true;
	}

	template<class T>
	void binary_search_tree<T>::insert(const T &data, node_ptr &node) const
	{
		if (!node)
			node = std::make_unique<binary_node>(data);
		else if (data < node->data)
			insert(data, node->left);
		else if (data > node->data)
			insert(data, node->right);
	}

	template<class T>
	const T &binary_search_tree<T>::find_min_recurse(node_ptr &node)
	{
		// currently doesn't check if empty
		//if (empty()) return T();

		if (!node->left)
			return node->data;

		return find_min_recurse(node->left);
	}

	template<class T>
	const T &binary_search_tree<T>::find_max_recurse(node_ptr &node)
	{
		// currently doesn't check if empty

		if (!node->right)
			return node->data;

		return find_max_recurse(node->right);
	}

	template<class T>
	void binary_search_tree<T>::print_tree(node_ptr &node) const
	{
		if (!node)
			return;
		
		std::cout << node->data << " ";
		print_tree(node->left);
		print_tree(node->right);
	}
}// namespace drw