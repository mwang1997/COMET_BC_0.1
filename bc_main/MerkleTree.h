#pragma once
#include "stdafx.h"


class b_node {
private:
	b_node * left = NULL;
	b_node * right = NULL;
	b_node * parent = NULL;
	int element = -1;

	/*Getters and Setters*/

	void setParent(b_node *);

public:
	b_node();

	b_node(int);

	b_node(b_node *);

	/*Getters and Setters*/

	void setChild(b_node *);

	bool isFull();
};