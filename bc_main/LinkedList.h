#pragma once
#include "node.h"
#include "functor.h"

class LinkedList {
private:
	p_node head;
	p_node * tail;
	p_node * current;

	/*Getters and Setters*/
	void setTail(p_node * n);

	void setCurrent(p_node * n);

public:

	/*Constructors*/
	LinkedList();

	/*Public Functions*/
	void add(int element);

	void traverse(functor * f);
};