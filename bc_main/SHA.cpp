#include "stdafx.h"
#include "SHA.h"


LinkedList<std::bitset<512>> SHA::process(std::vector<std::string> information) {
	int index = 0;
	std::string str, sb = "";
	std::bitset<64> size;

	for (std::string s : information) {
		for (int a = 0; a < s.size(); a++) {
			for (int c = s.at(a), b = 0; b < 8; c /= 2, index++, b++) {
				//Reset the 512 blocks
				if (index == 512) {
					index = 0;
					list.add(std::bitset<512>(str));
					str = "";
				}
				
				//Set the 0
				if (c % 2 == 0) {
					sb = "0" + sb;
				}
				//Set the 1
				else {
					c--;
					sb = "1" + sb;
				}

				for (int i = 0; i < 64; i++) {
					if (size[i] == 0) {
						size[i] = 1;
						i = 64;
					}
					else {
						size[i] = 0;
					}
					//Debugging
					std::cout << size << '\n';
				}
			}
			str = str + sb;
			sb = "";
		}
	}
	
	//Padding
	str = str + "1";
	if (str.size() > 448) {
		while (str.size() < 512) {
			str = str + "0";
			list.add(std::bitset<512>(str));
		}
		str = "";
	}
	if (str.size() < 448) {
		while (str.size() < 448) {
			str = str + "0";
		}
		//debugging
		std::cout << size << '\n';
		str = str + size.to_string();
	}

	list.add(std::bitset<512>(str));

	return list;
};