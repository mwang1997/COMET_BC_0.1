#pragma once
#include "ll_node.h"

template <class T> class LinkedList {
private:
	ll_node<T> head;
	ll_node<T> * current;
	ll_node<T> * tail;

	int size = -1;

public:
	LinkedList();

	void add(T element);

	T getLast();
	
	int getSize();

	T traverse();
};
	
template <class T> LinkedList<T>::LinkedList() : head(-1, NULL) {
	current = &head;
	tail = &head;
}

template <class T> void LinkedList<T>::add(T element) {
	size++;
	ll_node<T> * node = new ll_node<T>(tail->getIndex() + 1, element);
	tail->setNext(node);
	tail = node;
}

template <class T> T LinkedList<T>::getLast() {
	return tail->getElement();
}

template <class T> int LinkedList<T>::getSize() {
	return size;
}

template <class T> T LinkedList<T>::traverse() {
	if (current->getNext() == NULL) {
		current = &head;
		return NULL;
	}
	else {
		current = current->getNext();
		return current->getElement();
	}
}