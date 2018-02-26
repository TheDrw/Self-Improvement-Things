# dvector class

At the moment, it compiles and builds in visual studio 2017 and g++ 5.3.1-1ubuntu or something. 
The class lives in the drw namespace, so you'll need to use that.
There's no correlation with the name of the namespace and the name of my github.
The d from dvector is just the differentiate it from the vector class.
I have a feeling using this d to differentiate will probably haunt me later on.
There are no iterators at the moment. Hoping to implement that in the future. 
I was using a raw pointer for the array in the beginning but recently switched over to unique_ptr.
I am not sure if I am using unique_ptrs correctly.
So far, it seems fine with primitive data types. 
¯\_(ツ)_/¯