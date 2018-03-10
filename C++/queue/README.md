# queue_singly_list and queue_array class

At the moment, it compiles and builds in visual studio 2017 and g++ 5.3.1-1ubuntu or something. 
The class lives in the drw namespace, so you'll need to use that.

This is a simple implementation of a queue using a singly linked list.
Because this was kind of trivial, I don't need to provide test cases. 
I provided a print_queue function if you want to try it out.
I just did 10 pushes of i from 1 to 10, and 11 pops to test for any issues.
The pointer things are done the old style. I may change it to c++14 later.

The array version of the queue works fine at the moment.
It compiles with g++ -std=c++14 -Wall -Wextra -Werror main.cpp.
The queue is dynamic meaning the array it is used to hold the items grows and shrinks by depending how many items are in the queue.
It is pretty much a vector.  The array grows in powers of 2 after 4, so capacity is within \[4,inf). It is not really infinite, but you get the idea.
The tricky part when implementing this was how the keep track of the front and back when shrinking. 
I believe the tests I've put in main.cpp are fair enough to pass the basics of a queue.
It checks the when the array is changing in size and see's if the interaction with the array lines up with the queue.


I also think I might need to look into the linker issue more, but I can't for the life of me figure out
why there are linking problems. Hmm...all I can say is put the .cpp in your main to have it have no linking problems.
