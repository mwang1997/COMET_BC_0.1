#include "stdafx.h"
#include "LinkedList.h"
#include "functors.h"

int main() {
	LinkedList ll = LinkedList();

	ll.add(100);
	ll.add(83);
	ll.add(14);
	ll.add(993);

	LinkedList * list = new LinkedList();
	MerkleFunctor mf = MerkleFunctor(list);

	return 0;
}