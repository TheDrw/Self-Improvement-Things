# queue_singly_list class

At the moment, it compiles and builds in visual studio 2017 and g++ 5.3.1-1ubuntu or something. 
The class lives in the drw namespace, so you'll need to use that.

This is a simple implementation of a queue using a singly linked list.
Because this was kind of trivial, I don't need to provide test cases. 
I provided a print_queue function if you want to try it out.
I just did 10 pushes of i from 1 to 10, and 11 pops to test for any issues.

I think I might need to look into it more, but I can't for the life of me figure out
why there are linking problems. Hmm...all I can say is put the .cpp in your main to have it have no linking problems.