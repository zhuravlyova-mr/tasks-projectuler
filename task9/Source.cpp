#include <iostream>

using namespace std;

const int N = 1000;

int main() {
    int product, c;
    for (int a = 3; a < N / 3; ++a) {
        for (int b = a + 1; b < N - 1 - a; ++b) {
            c = N - a - b;
            if (a * a + b * b == c * c) {
           	 product = a * b * c;
                 cout << product;
                 return 0;
            }
        }
    }
    return 0;
}
