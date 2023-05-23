#include <iostream>
#include <string>

using namespace std;

const unsigned N = 1000000;

int main() {
    unsigned counter, max = 0, num, value;
    for (unsigned a = N-1; a > 0; --a) {
        num = a;
        counter = 1;
        do {
            num = (num % 2 == 0) ? (num / 2) : (3 * num + 1);
            ++counter;
        } while (num != 1);
        if (counter > max) {
            max = counter;
            value = a;
        }
    }
    cout << value;
}
