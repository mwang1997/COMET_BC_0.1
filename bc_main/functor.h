#pragma once

class p_node;

class functor {
public:
	virtual void f(p_node *) = 0;
};
