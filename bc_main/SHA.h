#pragma once
#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include "LinkedList.h"


class SHA {
private:	
	const std::bitset<32> h[8] = { 0x6a09e667,0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };

	LinkedList<std::bitset<512>> list;

public:
	LinkedList<std::bitset<512>> process(std::vector<std::string>);
};