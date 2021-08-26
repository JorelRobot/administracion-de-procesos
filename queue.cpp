#include "queue.hpp"

queue::queue(int c){

	n = c;
	s = 0;

	init = NULL;
	eoq = NULL;

}

queue::~queue(){


}

void queue::enqueue(long x, char name, int pri){

    /*
    if (full()) {

        printf("Queue overflow\n");
        return;
    }
    //*/
    if (empty()){
        init = eoq = new node(x, name, pri);
    }

    else {

        eoq -> next(new node(x, name, pri));
        eoq = eoq -> next();

        }
    s++;
}
/*
void queue::enqueue_middle(long x, char name, int pri){
    node* p = init;
    node* q;

    while(p && p -> data() < x){
        q = p;
        p = p -> next();
    }

    q.next(new node(x, name, pri));

    s++;
}
//*/
long queue::dequeue(){

    if (empty()){
		printf("Err: Empty queue \n ");
		return 0;
	}

	long x = init -> data();
	node *p = init;//inicio
	init = p -> next();//cambia el inicio
	delete p; //extrae el nodo

	if(!init) eoq = NULL;

	s--;

	return x;

}

node* queue::dequeue_save(){

    if (empty()){
		printf("Err: Empty queue \n ");
		return 0;
	}

	node* save = init;
	node* p = init; //inicio
	init = p -> next(); //cambia el inicio
	//delete p;   //extrae el nodo

	if(!init) eoq = NULL;

	s--;

	return save;
}

//*
long queue::data_front(){

	if (empty()){
		printf("Err: Empty queue \n ");
		return 0;
	}

	return init -> data();
}
//*/

node* queue::front(){

	if (empty()){
		printf("Err: Empty queue \n ");
		return 0;
	}

	return init;
}
