#include <iostream>
#include <string>

using namespace std;

const int N = 1000000;

bool isPalindrom(string s) {
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}

string toBinary(unsigned num, int base) {
    string s = "";
    while (num >= base) {
        s.push_back(num % base + '0');
        num = num / base;
    }
    s.push_back(num + '0');
    return s;
}

int main() {
    long sum = 0;
    for (unsigned num = 1; num < N; ++num) {
        if (isPalindrom(to_string(num)) && isPalindrom(toBinary(num, 2)))
            sum  += num;
    }
    cout << sum;
    return 0;
}
