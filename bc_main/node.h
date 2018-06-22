#pragma once
#include "MerkleTree.h"
class p_node{
private:
	p_node * next;
	int index = 0;

public:
	p_node(int);

	/*Getters and Setters*/
	p_node * getNext();

	int getIndex();

	int getElement();

	void setNext(p_node * n);

};

class t_node : public p_node {
private:
	int element = 0;

public:
	t_node(int, int);

	/*Getters and Setters*/

	int getElement();
};

class s_node : p_node {
private:
	b_node * element;

public:
	s_node(int, b_node *);
	
	b_node * getElement();
};
