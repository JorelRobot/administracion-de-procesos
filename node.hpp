#ifndef node_hpp
#define node_hpp

#include <cstdio>

class node{

    char _name;
	long _data;
	int _priority;
	node *_next;

	public:

		node(long, char, int);

		char name();
		long data();
		int priority();
		node *next();
		node *next(node *);

		void set_data(int);
};

#endif /* node_hpp */
