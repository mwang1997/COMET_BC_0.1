#pragma once
#include "ll_node.h"

template <class T> class LinkedList {
private:
	ll_node<T> head;
	ll_node<T> * tail;

public:
	LinkedList();

	void add(T element);
};

template <class T> LinkedList<T>::LinkedList() : head(-1, NULL) {
	tail = &head;
}

template <class T> void LinkedList<T>::add(T element) {
	ll_node<T> * node = new ll_node<T>(tail->getIndex() + 1, element);
	tail->setNext(node);
	tail = node;
}


