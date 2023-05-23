#include <iostream>

const int N = 2000000;

using namespace std;

int main() {
    long long sum = 2, j;
    for (int i = 3; i < N; ++i) {
        for (j = 2; j <= int(sqrt(i)); ++j) {
            if (i % j == 0) break;
        }
        if (j > int(sqrt(i)))
            sum += i;
    }
    cout << sum;
	return 0;
}