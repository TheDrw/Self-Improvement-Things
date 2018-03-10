#include "dstack_array.cpp"	// not best practices, i think

int main()
{
	drw::dstack_array<int> p {1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,6,7,8,9};
	std::cout << p.size() << '\n';
	p.print_stack();
	std::cout << p.top() << '\n';
	
	for(int i = 0; i < 15; i++) p.pop();
	p.print_stack();
	return 0;
}
