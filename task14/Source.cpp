#include <iostream>
#include <map>

const unsigned N = 1000000;

unsigned makeChain(unsigned n, std::map<unsigned, unsigned>& saved) {
	if (saved.find(n) != saved.end())
		return saved[n];
	if (n % 2 == 0)
		saved[n] = 1 + makeChain(n / 2, saved);
	else
		saved[n] = 2 + makeChain((3 * n + 1) / 2, saved);
	return saved[n];
}

int main() {
	unsigned longChain = 0, chain;
	unsigned res = -1;
	std::map<unsigned, unsigned> saved;
	saved[1] = 1;
	for (unsigned i = N / 2; i < N; ++i) {
		if ((chain = makeChain(i, saved)) > longChain) {
			longChain = chain;
			res = i;
		}
	}
	std::cout << res;
}

