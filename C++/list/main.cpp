//	Andrew Esberto
//	these are the basic tests when checking how beautifully bad my things are

#include "stdafx.h"		// for visual studio
#include <iostream>		// for debugging the bugs
#include <list>			// comparing list things
#include "dlist.cpp"	// not sure if this allowed but it was only way it would compile

//dlist lives in namespace drw::



void testingMyList()
{
	// testing if it works
	std::cout << "---------------------------------------------\n";
	std::cout << "testing if dlist crashes\n";
	drw::dlist<int> p;
	std::cout << "woot - dlist didn't crash, yet!\n";

	// testing clear when there's no nodes
	std::cout << "---------------------------------------------\n";
	std::cout << "testing clear() when there's no nodes\n";
	std::cout << "size before clear(): " << p.size() << "\n";
	p.clear();
	std::cout << "size after clear(): " << p.size() << "\n";

	// testing popping with no elements
	std::cout << "---------------------------------------------\n";
	std::cout << "testing popping with no elements\n";
	std::cout << "size: " << p.size() << "\n";
	p.pop_back();
	p.pop_front();

	// testing clear with one node
	std::cout << "---------------------------------------------\n";
	std::cout << "test clear() with one node\n";
	p.push_front(1111);
	std::cout << "size before clear(): " << p.size() << "\n";
	p.clear();
	std::cout << "size after clear(): " << p.size() << "\n";


	p.push_back(2222);
	std::cout << "size before clear(): " << p.size() << "\n";
	p.clear();
	std::cout << "size after clear(): " << p.size() << "\n";

	// testing for one node and popping them in different combinations
	std::cout << "---------------------------------------------\n";
	std::cout << "testing for one node and popping them in different combinations\n";
	p.push_front(-1);
	p.pop_front();

	p.push_front(-2);
	p.pop_back();

	p.push_back(-1);
	p.pop_front();

	p.push_back(10);
	p.pop_back();

	// testing clear when there's no nodes after popping
	std::cout << "---------------------------------------------\n";
	std::cout << "testing clear() when there's no nodes after popping\n";
	std::cout << "size before clear(): " << p.size() << "\n";
	p.clear();
	std::cout << "size after clear(): " << p.size() << "\n";

	// test when there's 2 nodes
	std::cout << "---------------------------------------------\n";
	std::cout << "testing when there's 2 nodes and popping them in different combinations\n";
	p.push_front(-420);
	p.push_back(420);
	std::cout << "front: " << p.front() << " back: " << p.back() <<  " size :" << p.size() << "\n";
	p.pop_front();
	std::cout << "front: " << p.front() << " back: " << p.back() << " size :" << p.size() << "\n";
	p.push_front(-420);
	p.pop_back();
	std::cout << "front: " << p.front() << " back: " << p.back() << " size :" << p.size() << "\n";
	p.push_back(420);

	// testing clear with 2 nodes
	std::cout << "---------------------------------------------\n";
	std::cout << "testing clear() with 2 nodes\n";
	p.clear();
	std::cout << "size :" << p.size() << "\n";


	// testing push_front with more nodes and checking the nodes and see how the size grows
	std::cout << "---------------------------------------------\n";
	std::cout << "testing push_front() with more nodes and checking size\n";
	for (int i = 0; i < 5; ++i)
	{
		p.push_front(i + 10);
		std::cout << p.front() << " " << p.back() << " " << p.size() << "\n";
	}

	// testing for pop_front for multiple nodes
	std::cout << "---------------------------------------------\n";
	std::cout << "testing pop_front() after pushing multiple nodes\n";
	p.pop_front();

	// testing push_back with more nodes and checking the nodes and see how size grows
	std::cout << "---------------------------------------------\n";
	std::cout << "testing push_back() and checking size\n";
	for (int i = 0; i < 5; ++i)
	{
		p.push_back(i + 100);
		std::cout << p.front() << " " << p.back() << " " << p.size() << "\n"; 
	}

	// testing pop_back for multiple nodes
	std::cout << "---------------------------------------------\n";
	std::cout << "testing pop_back() after pushing multiple nodes\n";
	p.pop_back();
	
	// testing clear() with many nodes
	std::cout << "---------------------------------------------\n";
	std::cout << "testing clear() after pushing multiple nodes\n";
	std::cout << "size before clear: " << p.size() << "\n";
	p.clear();
	std::cout << "size after clear: " << p.size() << "\n";

	// testing destructor
	std::cout << "---------------------------------------------\n";
	std::cout << "testing ~destruct0rz\n";
	for (int i = 0; i < 5; ++i) p.push_front(-69);
	
}

int main()
{
	testingMyList();

    return 0;
}