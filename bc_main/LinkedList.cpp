#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(0, -1) {
	tail = &head;
}

void LinkedList::setTail(node * n) {
	tail = n;
}

void LinkedList::add(int element) {
	//setTail(tail->setNext(*(new node(tail->getIndex() + 1, element))));
	node * n = new node(tail->getIndex() + 1, element);
	tail->setNext(n);
	setTail(n);
}

void LinkedList::traverse() {

}