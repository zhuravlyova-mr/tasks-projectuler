#include <iostream>
#include <set>

using namespace std;

int main() {
    set<double> terms;
    for (unsigned a = 2; a <= 100; ++a) {
        for (unsigned b = 2; b <= 100; ++b) {
            terms.insert(pow(a, b));
        }
    }
    cout << terms.size();
    return 0;
}
