#include "stdafx.h"
#include "block.h"

void block::add(int i) {
	transactions.add(new b_node(i));
}

void block::calculate() {

	LinkedList<b_node *> * l1 = new LinkedList<b_node *>;

	LinkedList<b_node *> * l2 = new LinkedList<b_node *>;

	b_node * n = transactions.traverse();

	b_node * p = new b_node();
	l1->add(p);

	while (n != NULL) {
		if (p->isFull()) {
			p = new b_node();
			l1->add(p);
		}

		p->setChild(n);
		n = transactions.traverse();
	}

	l2 = l1;
	l1 = new LinkedList<b_node *>;

	while (l2->getSize() != 1) {
		p = new b_node();
		l1->add(p);
		n = l2->traverse();


		while (n != NULL) {
			if (p->isFull()) {
				p = new b_node();
				l1->add(p);
			}

			p->setChild(n);
			n = l2->traverse();
		}

		l2 = l1;
		l1 = new LinkedList<b_node *>;
	}

	head = l2->traverse();
}

LinkedList<b_node *> block::getList() {
	return transactions;
}