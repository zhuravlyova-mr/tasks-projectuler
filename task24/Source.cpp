#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s = "0123456789";
    int counter = 0;
    do {
        ++counter;        
        if (counter == 1000000)
            cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    return 0;
}
