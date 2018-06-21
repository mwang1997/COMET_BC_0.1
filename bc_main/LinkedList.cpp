#include "stdafx.h"
#include "LinkedList.h"
#include "functor.h"

LinkedList::LinkedList() : head(0, -1) {
	tail = &head;
	current = &head;
}

void LinkedList::setTail(node * n) {
	tail = n;
}

void LinkedList::setCurrent(node * n) {
	current = n;
}
void LinkedList::add(int element) {
	node * n = new node(tail->getIndex() + 1, element);
	tail->setNext(n);
	this->setTail(n);
}

void LinkedList::traverse(functor * f) {
	if (current->getIndex() != tail->getIndex()) {
		f->f(current->getElement());
		setCurrent(current->getNext());
		traverse(f);
	}
	else {
		current = &head;
		return;
	}
}