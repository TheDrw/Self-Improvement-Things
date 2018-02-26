#include <iostream>		// used for lots of couts
#include <vector>		// used for comparisons and checking stuff
#include "dvector.cpp"	// not sure if this allowed but it was only way it would compile


void doVectorThings()
{
	std::vector<int> p;
	for (int i = 0; i < 50; ++i)
	{
		p.push_back(i);
		std::cout << p.capacity() << " " << p.size() << "\n";
	}

	for (int i = 0; i < 50; ++i)
	{
		p.pop_back();
		std::cout << p.capacity() << " " << p.size() << "\n";
	}
}

void testingMyVector()
{
	// test if it works
	drw::dvector<int> p;

	// test push_back
	for (int i = 0; i < 10; ++i)
	{
		p.push_back(i + 10);
		std::cout << p.capacity() << " " << p.size() << " index: " << i << " " << p[i] << "\n";
	}

	std::cout << "---------------------------------------------\n";
	// test clear
	p.clear();
	std::cout << "After clear : " << p.capacity() << "  " << p.size() << "\n";

	std::cout << "---------------------------------------------\n";
	// test if clear, push_back and capacity goes unchanged
	for (int i = 0; i < 10; ++i)
	{
		p.push_back(i + 10);
		std::cout << p.capacity() << " " << p.size() << " index: " << i << " " << p[i] << "\n";
	}

	std::cout << "---------------------------------------------\n";
	// test pop_back and how the size is affected.
	for (int i = 0; i < 3; ++i)
	{
		p.pop_back();
		std::cout << p.capacity() << " " << p.size() << "\n";
	}

	std::cout << "---------------------------------------------\n";
	// test shrink_to_fit and how capacity and size change
	p.shrink_to_fit();
	std::cout << p.capacity() << " " << p.size() << "\n";
	std::cout << "---------------------------------------------\n";
	// test if elements are still in their spots
	for (int i = 0; i < p.size(); ++i)
	{
		std::cout << p[i] << " ";
	}

	std::cout << "\n";
	std::cout << "---------------------------------------------\n";
	// test how it grows after shrunk_to_fit was called by pushing elements into it
	std::cout << p.capacity() << " " << p.size() << "\n";
	for (int i = 0; i < 30; ++i)
	{
		p.push_back(i + 10);
		std::cout << p.capacity() << " " << p.size() <<  " " << p[p.size() - 1] << "\n";
	}

	std::cout << "---------------------------------------------\n";
	// test how it behaves when it copies another dvector
	drw::dvector<int> a(1); // makes 1 element of a zero
	p = a;
	std::cout << p.capacity() << " " << p.size() << " " << p[p.size() - 1] << "\n";


	std::cout << "---------------------------------------------\n";
	// test if copying vector into a new vector
	drw::dvector<int> b(p);
	std::cout << b.capacity() << " " << b.size() << " " << b[b.size() - 1] << "\n";


	std::cout << "---------------------------------------------\n";
	// testing filling in container with a value upon initialization 
	drw::dvector<int> c(10, 69);
	std::cout << c.capacity() << " "  << c.size();
	for (int i = 0; i < c.size(); ++i)
	{
		std::cout << c[i] << " ";
	}
}

int main()
{
	testingMyVector();
    return 0;
}