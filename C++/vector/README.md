# dvector class

At the moment, it compiles and builds in visual studio 2017 and g++ 5.3.1-1ubuntu or something.
Compiles with g++ -std=c++14 -Wall -Wextra -Werror main.cpp. 
With -std=c++11 throws errors because std::make_unique wasn't born yet.
The class lives in the drw namespace, so you'll need to use that.

There's no correlation with the name of the namespace and the name of my github.
The d from dvector is just the differentiate it from the vector class.
I have a feeling using this d to differentiate will probably haunt me later on.
Comments are mainly for me to remember things and not for actual documentation.
So far, it seems fine with primitive data types. 
¯\_(ツ)_/¯
