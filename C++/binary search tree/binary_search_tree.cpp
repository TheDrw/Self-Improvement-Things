// andrew esberto
#include "stdafx.h"
#include "binary_search_tree.h"

namespace drw
{
	template<class T>
	binary_search_tree<T>::binary_search_tree()
		: root(), node_count(0)
	{}

	template<class T>
	binary_search_tree<T>::binary_search_tree(std::initializer_list<T> i_list)
		: node_count(0)
	{
		for (const auto &item : i_list) insert(item);
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
		//if (empty()) return 123;

		return find_min_recurse(root)->data;
		//return temp->data;
	}

	template<class T>
	const T &binary_search_tree<T>::find_max_recurse()
	{
		//if (empty()) return 123;

		return find_max_recurse(root)->data;
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
	void binary_search_tree<T>::remove(const T &data)
	{
		if (empty()) return;

		remove(data, root);
	}

	template<class T>
	void binary_search_tree<T>::make_empty()
	{
		node_count = 0;
		root.reset();
	}

	template<class T>
	void binary_search_tree<T>::print_tree_preorder()
	{
		print_tree(root, 0);
		std::cout << '\n';
	}

	template<class T>
	void binary_search_tree<T>::print_tree_inorder()
	{
		print_tree(root, 1);
		std::cout << '\n';
	}

	template<class T>
	void binary_search_tree<T>::print_tree_postorder()
	{
		print_tree(root, 2);
		std::cout << '\n';
	}

	template<class T>
	void binary_search_tree<T>::depth_of_tree()
	{
		int depth = 0;
		depth_of_tree(root, 0, depth);
		std::cout << "depth : " << depth << '\n';
	}

	//////////////////////////////////////////////////////////////////
	////////////////////  private functions	  ////////////////////////
	//////////////////////////////////////////////////////////////////
	// these will all mainly be recursive calls

	template<class T>
	const bool binary_search_tree<T>::contains(const T &data, node_ptr &node)
	{
		if (!node)
			return false;
		else if (is_less_than(data, node->data))
			return contains(data, node->left);
		else if (is_less_than(node->data, data))
			return contains(data, node->right);
		else
			return true;
	}

	template<class T>
	void binary_search_tree<T>::insert(const T &data, node_ptr &node) const
	{
		if (!node)
			node = std::make_unique<binary_node>(data);
		else if (is_less_than(data, node->data))
			insert(data, node->left);
		else if (is_less_than(node->data, data))
			insert(data, node->right);
	}

	template<class T>
	void binary_search_tree<T>::remove(const T &data, node_ptr &node)
	{
		if (!node)
		{
			return;
		}
		else if (is_less_than(data, node->data))
		{
			remove(data, node->left);
		}
		else if (is_less_than(node->data, data))
		{
			remove(data, node->right);
		}
		else if (node->left && node->right)
		{
			node->data = find_min_recurse(node->right)->data;
			remove(node->data, node->right);
		}
		else
		{
			node = (node->left) ? std::move(node->left) : std::move(node->right);
		}
	}

	template<class T>
	typename binary_search_tree<T>::binary_node *binary_search_tree<T>::find_min_recurse(node_ptr &node)
	{
		if (!node->left) return node.get();

		return find_min_recurse(node->left);
	}

	template<class T>
	typename binary_search_tree<T>::binary_node *binary_search_tree<T>::find_max_recurse(node_ptr &node)
	{
		if (!node->right) return node.get();

		return find_max_recurse(node->right);
	}

	// pass in 0 - preoder, 1 - inorder, 2 - postorder.
	template<class T>
	void binary_search_tree<T>::print_tree(node_ptr &node, int order) const
	{
		if (!node) return;

		if (order == 0) print_node(node);

		print_tree(node->left, order);
		if (order == 1) print_node(node);

		print_tree(node->right, order);
		if (order == 2) print_node(node);
	}

	template<class T>
	void binary_search_tree<T>::print_node(node_ptr &node) const
	{
		std::cout << "dat: " << node->data << "\tnode addr: " << node.get() << "\tleft addr: " << node->left.get() << "\tright addr: " << node->right.get() << '\n';
	}

	template<class T>
	void binary_search_tree<T>::depth_of_tree(node_ptr &node, int curr_depth, int &max_depth)
	{
		if (!node) return;

		depth_of_tree(node->left, curr_depth + 1, max_depth);
		depth_of_tree(node->right, curr_depth + 1, max_depth);

		if (curr_depth > max_depth) max_depth = curr_depth;
	}

	template<class T>
	const bool binary_search_tree<T>::is_less_than(const T &val_a, const T &val_b) const
	{
		return val_a < val_b;
	}
}// namespace drw