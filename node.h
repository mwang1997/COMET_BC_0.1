<<<<<<< HEAD
#pragma once

class node {
private:
	node * next;
	int element = 0;
	int index = 0;

public:
	node(int, int);

	/*Getters and Setters*/
	node getNext();

	int getIndex();

	int getElement();

	void setNext(node * n);



};
=======
#pragma once

class node {
private:
	node * next;
	int element = 0;
	int index = 0;

public:
	node(int, int);

	/*Getters and Setters*/
	node getNext();

	int getIndex();

	int getElement();

	void setNext(node * n);



};
>>>>>>> 82d2e908315b8173d596e1c6bcdf72013f3dd15b
