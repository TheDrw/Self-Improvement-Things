# dstack_array / dstack_list / dstack_list_singly class

At the moment, it compiles and builds in visual studio 2017 and g++ 5.3.1-1ubuntu or something. 
The class lives in the drw namespace, so you'll need to use that.


Because the implementation of stack is fairly trivial, I didn't run many tests.
I made an array and list version of stack. The array is like a vector in a sense.

The list version is a doubly linked list with less features.
I just copy and pasted the dnode class in the dstack_list class, so no linking errors will occur.
I did it this way to have less files. Most likely, I wouldn't do that in a project.

I also implemented a singly linked list version of the stack.
It is fairly straight forward. The dnode class is changed around a little bit to make it fit.
It is also in the header of dstack_list_singly to avoid any linking issues and have less files.

Anyways, most of the code is just reused and fitted from the other classes because they're very similar. 