#pragma once
#include "node.h"
#include "functor.h"

class LinkedList {
private:
	node head;
	node * tail;
	node * current;

	/*Getters and Setters*/
	void setTail(node * n);

	void setCurrent(node * n);

public:

	/*Constructors*/
	LinkedList();

	/*Public Functions*/
	void add(int element);

	void traverse(functor * f);
};