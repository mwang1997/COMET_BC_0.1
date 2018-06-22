#include "stdafx.h"
#include "node.h"

/*Parent Node*/

p_node::p_node(int i) {
	index = i;
	next = NULL;
}

/*Getters and Setters*/

 p_node * p_node::getNext() {
	return next;
}

 int p_node::getIndex() {
	 return index;
 }

 void p_node::setNext(p_node * n) {
	 next = n;
 }

 /*Transaction Node*/

 t_node::t_node(int i, int e) : p_node(i) {
	 element = e;
 }

 int t_node::getElement() {
	 return element;
 }

 /*Structure Node*/

 s_node::s_node(int i, b_node * e) : p_node(i) {
	 element = e;
 }