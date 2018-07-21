#include "stdafx.h"
#include "LinkedList.h"
#include "block.h"
#include "SHA.h"

int main() {
	LinkedList<int> ll;
	for (int i = 0; i < 500000; i++) {
		ll.add(i + 32);
	}

	block b;

	for (int i = 0; i < 500000; i++) {
		b.add(i + 32);
	}

	b.calculate();

	SHA sha;

	std::vector<std::string> s;

	s.push_back("hello ");
	s.push_back("cows ");
	s.push_back("donkey ");
	s.push_back("the quick brown fox skips the hog ");
	s.push_back("stop writing random characters ");

	std::cout << sha.process(s);

	return 0;

}