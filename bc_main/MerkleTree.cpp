#include "stdafx.h"
#include "MerkleTree.h"

/*Constructor*/

b_node::b_node() {

}

b_node::b_node(int e) {
	element = e;
}

bool b_node::isFull() {
	return (right != NULL);
}

bool b_node::hasParent() {
	return (parent != NULL);
}

/*Getters and Setters*/

void b_node::setParent(b_node * n) {
	parent = n;
}

void b_node::setChild(b_node * n) {
	if (left == NULL) {
		left = n;
		n->setParent(this);
	}
	else if (right == NULL) {
		right = n;
		n->setParent(this);
	}
}
