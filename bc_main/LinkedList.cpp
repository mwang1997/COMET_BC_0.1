#include "stdafx.h"
#include "LinkedList.h"
#include "functor.h"
#include "MerkleTree.h"
#include <iostream>

LinkedList::LinkedList() : head(-1) {
	tail = &head;
	current = &head;
}

p_node * LinkedList::getLast() {
	return tail;
}

void LinkedList::setTail(p_node * n) {
	tail = n;
}

void LinkedList::setCurrent(p_node * n) {
	current = n;
}
void LinkedList::add(int element) {
	t_node * n = new t_node(tail->getIndex() + 1, element);
	tail->setNext(n);
	this->setTail(n);
}

void LinkedList::add(b_node * element) {
	s_node * n = new s_node(tail->getIndex() + 1, element);
	tail->setNext(n);
	this->setTail(n);
}

void LinkedList::traverse(functor * f) {
	if (current->getIndex() != tail->getIndex()) {
		f->f(current);
		setCurrent(current->getNext());
		traverse(f);
	}
	else {
		current = &head;
		return;
	}
}