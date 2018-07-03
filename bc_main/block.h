#pragma once
#include "LinkedList.h"
#include "MerkleTree.h"

class block {
private:
	LinkedList<b_node *> transactions;
	b_node * head;
	block * previous;

public:
	void add(int);

	void calculate();

	/*Getters and Setters*/
	void getList();
};