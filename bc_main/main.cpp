#include "stdafx.h"
#include "LinkedList.h"

int main() {
	LinkedList<int> ll;
	for (int i = 0; i < 100; i++) {
		ll.add(i + 32);
	}

	return 0;
}