#include "stdafx.h"
#include "SHA.h"


std::bitset<256> SHA::process(std::vector<std::string> information) {
	int index = 0;
	std::string str, sb = "";
	std::bitset<64> size;

	for (std::string s : information) {
		for (int a = 0; a < s.size(); a++) {
			for (int c = s.at(a), b = 0; b < 8; c /= 2, index++, b++) {
				//Reset the 512 blocks
				if (index == 512) {
					index = 0;
					list.push_back(std::bitset<512>(str));
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
			list.push_back(std::bitset<512>(str));
		}
		str = "";
	}
	if (str.size() < 448) {
		while (str.size() < 448) {
			str = str + "0";
		}
		str = str + size.to_string();
	}

	list.push_back(std::bitset<512>(str));
	
	std::bitset<32> h[8] = { 0x6a09e667,0xbb67ae85, 0x3c6ef372, 0xa54ff53a, 0x510e527f, 0x9b05688c, 0x1f83d9ab, 0x5be0cd19 };
	std::bitset<32> z[8];
	std::bitset<32> W[64];
	std::bitset<32> Ch, Maj, S1, S0, s0, s1, W1, T1, T2;

	for (std::bitset<512> b : list) {
		W->reset();

		for (int i = 0; i < 7; i++) {
			z[i] = std::bitset<32>(h[i].to_string());
		}

		for (int x = 0; x < 64; x++) {
				
			Ch = (h[4] & h[5]) ^ (~h[4] ^ h[6]);
			Maj = (h[4] & h[5]) ^ (h[4] & h[6]) ^ (h[5] & h[6]);
			S0 = rrotate(2, h[4]) ^ rrotate(13, h[4]) ^ rrotate(22, h[4]);
			S1 = rrotate(6, h[4]) ^ rrotate(11, h[4]) ^ rrotate(25, h[4]);
			s0 = rrotate(7, h[4]) ^ rrotate(18, h[4]) ^ rshift(3, h[4]);
			s1 = rrotate(17, h[4]) ^ rrotate(19, h[4]) ^ rshift(10, h[4]);
			W1 = w(x, b, W);
			T1 = t1(h[7], S1, Ch, k[x], W1);
			T2 = std::bitset<32>((S0.to_ullong() + Maj.to_ullong()) % 4294967296);
			
			
			z[7] = std::bitset<32>(z[6].to_string());
			z[6] = std::bitset<32>(z[5].to_string());
			z[5] = std::bitset<32>(z[4].to_string());
			z[4] = std::bitset<32>((z[3].to_ullong() + T1.to_ullong()) % 4294967296);
			z[3] = std::bitset<32>(z[2].to_string());
			z[2] = std::bitset<32>(z[1].to_string());
			z[1] = std::bitset<32>(z[0].to_string());
			z[0] = std::bitset<32>((T2.to_ullong() + T1.to_ullong()) % 4294967296);
		
		}

		for (int y = 0; y < 8; y++) {
			h[y] = std::bitset<32>((z[y].to_ullong() + h[y].to_ullong()) % 4294967296);
		}
	}

	std::string s;

	for (std::bitset<32> hash : h) {
		s = s + hash.to_string();
	}

	return std::bitset<256>(s);
};


std::bitset<32> SHA::rrotate(int i, std::bitset<32> b) {
	std::bitset<32> y = std::bitset<32>(b.to_string()); 
	for (int x = 0, z = y[0]; x < i; x++) {
		y >> 1;
		y[31] = z;
	}
	return y;
}

std::bitset<32> SHA::rshift(int i, std::bitset<32> b) {
	std::bitset<32> y = std::bitset<32>(b.to_string());
	return y >> i;
}

std::bitset<32> SHA::w(int i, std::bitset<512> b, std::bitset<32> W[64]) {
	if (W[i].any()) {
		return W[i];
	}
	if (i < 16) {
		return W[i] = std::bitset<32>(b.to_string().substr(i * 32, i * 32 + 32));
	}
	else {
		unsigned long long r = 0;
		r = (rrotate(17, w(i - 2, b, W)) ^ rrotate(19, w(i - 2, b, W)) ^ rshift(10, w(i - 2, b, W))).to_ullong();
		r = (r + (w(i - 7, b, W)).to_ullong()) % 4294967296;;
		r = (r + (rrotate(7, w(i - 15, b, W)) ^ rrotate(18, w(i - 15, b, W)) ^ rshift(3, w(i - 15, b, W))).to_ullong()) % 4294967296;
		r = (r + (w(i - 16, b, W)).to_ullong()) % 4294967296;

		std::cout << r << '\n';
		W[i] = std::bitset<32>(r);
		return W[i];
	}
}

std::bitset<32> SHA::t1(std::bitset<32> a, std::bitset<32> b, std::bitset<32> c, std::bitset<32> d, std::bitset<32> e) {
	unsigned long long r = a.to_ullong();
	r = (r + b.to_ullong()) % 4294967296;
	r = (r + c.to_ullong()) % 4294967296;
	r = (r + d.to_ullong()) % 4294967296;
	r = (r + e.to_ullong()) % 4294967296;

	return std::bitset<32>(r);
}
