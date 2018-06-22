#pragma once
#include "functor.h"
#include "LinkedList.h"

class MerkleFunctor : public functor {
private:
	LinkedList l;


public:
	void f(p_node *);

	LinkedList getItem();


};