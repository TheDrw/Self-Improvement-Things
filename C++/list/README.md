# dlist class and dforward_list class

At the moment, it compiles and builds in visual studio 2017 and g++ 5.3.1-1ubuntu or something.
The dlist class is a doubly linked list. The dnode class is setup for doubly linked list.
I've only tested dlist with primitive data types.
So far it seems fine. Because I didn't implement iterators, I'm most likely going to leave it as is. 
The functions implemented work as intended.


The dforward_list class is a singly linked list. It also uses the dnode class, but ignores the prev pointer it provides.
I didn't test much with dforward_list because most of the ideas carry over from dlist. I assume the core parts work. 
I checked for any segfaults and incorrect readings for remove() and pop_front(). So far, seems fine. 
I don't think I'll work on it anymore than what is already here. dforward_list list also seems to work fine with primitive types.
Again, just like the dlist class, there's no iterators.


Hoping for pizza in the near future. 
I still feel like I am not using github correctly. I am using this more like a blog of my demise.
¯\_(ツ)_/¯