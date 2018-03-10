// Andrew Esberto - tests for binary_search_tree
#include <iostream>
#include <string>
#include "binary_search_tree.cpp"	// not best practices but will do

int main()
{
	drw::binary_search_tree<int> p = { 10,12,5,6,7,51,2,1,3,11 };
	//drw::binary_search_tree<int> p = { 6,2,1,5,3,4 };
	//drw::binary_search_tree<int> p = { 10,2,1,8,3,4,5,6 };
	std::cout << "EMPTY: " << (p.empty() ? "true\n" : "false\n");
	std::cout << "\n";


	p.print_tree_preorder();
	p.print_tree_inorder();
	p.print_tree_postorder();
	int find_num = 51;
	std::cout << ( p.contains(find_num) ? ("yes, it contains " + std::to_string(find_num)) : "no, it donts containts it") << '\n';
	std::cout << "min : " << p.find_min_recurse() << '\n';
	std::cout << "max : " << p.find_max_recurse() << '\n';
	p.remove(2);
	p.print_tree_preorder();
	p.make_empty();
	std::cout << "EMPTY: " << (p.empty() ? "true\n" : "false\n");

    return 0;
}