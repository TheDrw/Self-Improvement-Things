# dstack_array and dstack_list class

At the moment, it compiles and builds in visual studio 2017 and g++ 5.3.1-1ubuntu or something. 
The class lives in the drw namespace, so you'll need to use that.


Because the implementation of stack is fairly trivial, I didn't run many tests.
I made an array and list version of stack. The array is like a vector in a sense.
And the list version is a doubly linked list with less features.
I just copy and pasted the dnode class in the dstack_list class, so no linking errors will occur.
I did it this way to have less files. Most likely, I wouldn't do that in a project.
Anyways, most of the code is just reused and fitted from the other classes because they're very similar. 