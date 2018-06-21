#pragma once
#include "functor.h"
#include "LinkedList.h"

class MerkleFunctor : public functor {
private:
	LinkedList l;


public:
	void f(int);

	LinkedList getItem();


};