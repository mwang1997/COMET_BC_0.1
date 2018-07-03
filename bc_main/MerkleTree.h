#pragma once
#include "stdafx.h"

class b_node {
private:
	b_node * left = NULL;
	b_node * right = NULL;
	b_node * parent = NULL;
	int element = NULL;

public:
	b_node();

	b_node(int e);

	bool isFull();

	bool hasParent();

	/*Getters and Setters*/

	void setChild(b_node *);

	void setParent(b_node *);
};
