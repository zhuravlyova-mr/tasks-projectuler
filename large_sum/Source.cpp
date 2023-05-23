#include <iostream>
#include <fstream>

using namespace std;

const int n = 100;
const int m = 50;

void summator(uint16_t* sum, uint16_t* number, int8_t& lenS, int8_t lenN) {
	uint8_t carryOver = 0, s, i;
	uint8_t len = lenS < lenN ? lenS : lenN;
	for (i = 0; i < len; ++i) {
		sum[i] = ((s = sum[i] + number[i])) % 10 + carryOver;    //write digit
		carryOver = s / 10;										 //remember carryOver
	}
	while (carryOver > 0) {										//correcting the sum if necessary
		sum[i] = (s = sum[i] + carryOver) % 10;
		carryOver = s / 10;
		++i;
	}
	if (lenS < i)
		lenS = i;
}

int main() {

	std::ifstream in("../../file.txt");
	if (!in.is_open()) {
		throw std::invalid_argument("File not found!");
	}
	uint16_t sum[n] = { 0 };
	uint16_t num[m];
	int8_t lenS = m, lenN = m, i;
	char ch = '\0';
	for (i = m - 1; i >= 0; --i) {   //reading the first number
		in >> ch;
		sum[i] = ch - '0';
	}
	while (!(in.eof())) {
		for (i = m - 1; i >= 0; --i) {
			in >> ch;
			num[i] = ch - '0';
		}
		summator(sum, num, lenS, lenN);     
	}
	for (int8_t i = lenS-1; i > lenS-11; --i)
		cout << sum[i] << " ";
	return 0;
}