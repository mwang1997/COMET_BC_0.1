#include "stdafx.h"
#include "LinkedList.h"
#include "block.h"

int main() {
	LinkedList<int> ll;
	for (int i = 0; i < 100; i++) {
		ll.add(i + 32);
	}

	block b;

	for (int i = 0; i < 100; i++) {
		b.add(i + 32);
	}

	b.calculate();

	return 0;

}