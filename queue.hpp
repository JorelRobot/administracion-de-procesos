#ifndef queue_hpp
#define queue_hpp

#include <cstdio>
#include "node.hpp"

class queue{

	int n;
	int s;

	node *init;
	node *eoq;

	public:

		queue(int);
		~queue();

		void enqueue(long, char, int);
		//void enqueue_middle(long, char, int);
		long dequeue();
		node* dequeue_save();
		long data_front();
		node* front();


		int capacity() { return n; }
		int size() { return s; }

		bool empty(){ return s == 0;}
		bool full(){ return s == n; }

};

#endif /* queue_hpp*/
