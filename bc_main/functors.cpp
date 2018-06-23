#include "stdafx.h"
#include "functors.h"
#include <typeinfo>

MerkleFunctor::MerkleFunctor(LinkedList * l) {
	setItem(l);
}

void MerkleFunctor::f(s_node * n) {
	if (temp == NULL) {
		temp = new b_node();
	}
	else if (temp->isFull()) {
		list->add(temp);
		temp = new b_node();
	}
	else {
		temp->setChild(n->getElement());
	}
}

void MerkleFunctor::f(t_node * n) {
	list->add(new b_node(n->getElement()));
}

LinkedList * MerkleFunctor::getItem() {
	return list;
}

void MerkleFunctor::setItem(LinkedList * l) {
	list = l;
}

