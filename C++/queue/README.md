# queue_singly_list and queue_array class

At the moment, it compiles and builds in visual studio 2017 and g++ 5.3.1-1ubuntu or something. 
The class lives in the drw namespace, so you'll need to use that.

This is a simple implementation of a queue using a singly linked list.
Because this was kind of trivial, I don't need to provide test cases. 
I provided a print_queue function if you want to try it out.
I just did 10 pushes of i from 1 to 10, and 11 pops to test for any issues.

The array version of the queue works fine at the moment. But the only problem is I want it to shrink when
it reaches a certain number of items on the stack. Other than that, it will grow and work fine.
So at the moment, there's a lot of couts everywhere. I'll fix it soon, I hope.
Me thinking of the array circular is kind of hurting my brain. I'm not used to it.
I'm not used to using my brain, that is.

I also think I might need to look into the linker issue more, but I can't for the life of me figure out
why there are linking problems. Hmm...all I can say is put the .cpp in your main to have it have no linking problems.