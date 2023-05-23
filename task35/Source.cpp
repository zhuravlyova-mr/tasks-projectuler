#include <iostream>

const unsigned N = 1000000;

using namespace std;

bool isSimple(unsigned n) {
    if (n == 2)
        return true;
    int j;
    for (j = 2; j <= int(sqrt(n)); ++j) {
        if (n % j == 0) break;
    }
    if (j > int(sqrt(n))) return true;
    else return false;
}

unsigned rotate(unsigned n) {                    //cyclic shift
    unsigned res = n % 10, length = 1, digits;
    digits = n /= 10;
    while (n > 0) {
        length *= 10;
        n /= 10;
    }
    res = res * length + digits;
    return res;
}

int main() {
    unsigned account = 13, rotated = 0, temp;
    for (unsigned i = 101; i < N; ++i) {
        if (!isSimple(i))
            continue;
        temp = i;
        while (true) {
            rotated = rotate(temp);
            if (rotated == i)
                break;
            if (!isSimple(rotated))
                break;
            temp = rotated;
        }
        if (rotated == i)
            ++account;
    }
    cout << account;
    return 0;
}
