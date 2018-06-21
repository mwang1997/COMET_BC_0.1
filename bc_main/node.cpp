#include "stdafx.h"
#include "node.h"

node::node(int i, int e) {
	index = i;
	element = e;
	next = NULL;
}

 node node::getNext() {
	return *next;
}

 int node::getIndex() {
	 return index;
 }

 int node::getElement() {
	 return element;
 }

 void node::setNext(node * n) {
	 next = n;
 }