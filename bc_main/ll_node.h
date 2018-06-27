#pragma once
#include "stdafx.cpp"

template <class T> class ll_node {
private:
	T element;
	int index;
	ll_node<T> * next;

public:
	/*Constructor*/
	ll_node(int, T);

	/*Getters and Setters*/
	ll_node<T> * getNext();

	int getIndex();

	T getElement();

	void setNext(ll_node<T> *);
};


/*Constructor*/
template <class T> ll_node<T>::ll_node(int i, T e) {
	index = i;
	element = e;
}

/*Getters and Setters*/
template <class T> ll_node<T> * ll_node<T>::getNext() {
	return next;
}

template <class T> int ll_node<T>::getIndex() {
	return index;
}

template <class T> T ll_node<T>::getElement() {
	return element;
}

template <class T> void ll_node<T>::setNext(ll_node<T> * n) {
	next = n;
}

#pragma once
