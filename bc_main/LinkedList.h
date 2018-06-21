#pragma once
#include "node.h"

class LinkedList {
private:
	node head;
	node * tail;

	/*Getters and Setters*/
	void setTail(node * n);

public:

	/*Constructors*/
	LinkedList();

	void add(int element);

	void traverse();
};