#include "node.hpp"

node::node(long x, char n, int pri){

    _name = n;
	_data = x;
	_priority = pri;
	_next = NULL;

}

char node::name(){
    return _name;
}

long node::data(){
	return _data;
}

int node::priority(){
    return _priority;
}

node *node::next(){
	return _next;
}

node *node::next(node *p){
	return _next = p;
}

void node::set_data(int change){
    _data = change;
}
