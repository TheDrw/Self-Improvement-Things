# binary_search_tree class

At the moment, it compiles and builds in visual studio 2017 and g++ 5.3.1-1ubuntu or something.
Using g++ -std=c++14 -Wall -Wextra -Werror main.cpp doesn't pop up errors. 
Compiling with -std=c++11 throws errors because std::make_unique wasn't implemented yet, I think.
All the classes live in the drw namespace, so keep that in mind.

The basics of inserting works and checking if the BST contains a certain item.
I think the remove targeted node works, too. 
I feel like my code is starting to look more like C++11/14.
