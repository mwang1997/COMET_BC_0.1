<<<<<<< HEAD
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
=======
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
>>>>>>> 82d2e908315b8173d596e1c6bcdf72013f3dd15b
};