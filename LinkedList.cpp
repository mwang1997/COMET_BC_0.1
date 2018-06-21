<<<<<<< HEAD
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

=======
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

>>>>>>> 82d2e908315b8173d596e1c6bcdf72013f3dd15b
}