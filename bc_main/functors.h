#pragma once
#include "functor.h"
#include "LinkedList.h"

class MerkleFunctor : public functor {
private:
	LinkedList * list = NULL;
	b_node * temp = NULL;


public:
	MerkleFunctor(LinkedList *);

	void f(s_node *);

	void f(t_node *);

	/*Getters and Setters*/

	LinkedList * getItem();

	void setItem(LinkedList *);
};