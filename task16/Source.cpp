#include <iostream>
#include <string>

using namespace std;

int main() {

    long double sum = pow(2, 1000);
    string str = to_string(sum);
    long sumOfDigits = 0;
    for (int i = 0; str[i] != '.' && str[i] != ','; ++i)
        sumOfDigits += str[i] - '0';
    cout << sumOfDigits;
    return 0;
}
