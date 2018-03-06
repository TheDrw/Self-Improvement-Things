// Andrew Esberto

#include "stdafx.h"		// for visual studio
#include "queue_singly_list.cpp"
#include "queue_array.cpp"
#include <queue>
#include <string>

int main()
{
	drw::queue_array<int> q;
	std::queue<int> p;

	int loops = 5;
	for (int i = 0; i < 50; ++i)
	{
		// pushing
		for (int i = 0; i < loops; ++i)
		{
			q.push(i + 1);
			p.push(i + 1);
			q.print_queue();
		}

		loops = 4;
		// popping
		for (int i = 0; i < loops; ++i)
		{
			q.pop();
			p.pop();
			q.print_queue();
		}
		loops = 6;
	}

	// the number of loops here have to be lower than above or std::queue will be mad if it pops passed empty
	for (int i = 0; i < 20; ++i)
	{
		// popping
		for (int i = 0; i < loops; ++i)
		{
			q.pop();
			p.pop();
			q.print_queue();
		}

		loops = 4;
		// pushing
		for (int i = 0; i < loops; ++i)
		{
			q.push(i + 1);
			p.push(i + 1);
			q.print_queue();
		}
		loops = 8;
	}

	std::cout << "\n--------------------------------\n";
	int mySum = 0;
	int realSum = 0;

	std::cout << "\nmy queue : ";
	while (!q.empty())
	{
		std::cout << q.front() << ", ";
		mySum += q.front();
		q.pop();
	}
	std::cout << " \nmy sum : " << mySum << "\n";

	std::cout << "real queue : ";
	while (!p.empty())
	{
		std::cout << p.front() << ", ";
		realSum += p.front();
		p.pop();
	}
	std::cout << " \nactual sum : " << realSum << "\n\n";
	std::cout << "Does my queue match with real queue? " << (mySum == realSum ? "YES" : "sadly, NAW") << "\n\n";

    return 0;
}