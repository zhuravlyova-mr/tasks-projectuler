#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<string, int>> words = { {"", 0}, {"one", 3}, {"two", 3}, {"three", 5}, {"four", 4}, {"five", 4}, {"six", 3}, {"seven", 5},
                           {"eight", 5}, {"nine", 4}, {"ten", 3}, {"eleven", 6}, {"twelve", 6}, {"thirteen", 8}, {"fourteen", 8}, {"fifteen", 7},
                            {"sixteen", 7}, {"seventeen", 9}, {"eighteen", 8}, {"nineteen", 8}, {"twenty", 6}, {"thirty", 6}, {"forty", 5}, {"fifty", 5},
                            {"sixty", 5}, {"seventy", 7}, {"eighty", 6}, {"ninety", 6}, {"hundred", 7}};

void calculate(unsigned& sum) {
    unsigned tiny_sum = 0;
    unsigned large_sum = 0;
    auto r = words.begin() + 1;
    for (; (*r).first != "ten"; ++r) {
        sum += (*r).second;
    }
    tiny_sum = sum;
    for (; (*r).first != "twenty"; ++r) //up to 19
        sum += (*r).second;
    for (auto r = words.begin() + 20; (*r).first != "hundred"; ++r) { //up to 99
        sum += 10*(*r).second + tiny_sum;
    }
    large_sum = sum;  //from 1 to 99
    sum += (large_sum + 10 * 99) * 9 + tiny_sum * 100; //9 times large_sum & 'hundred and' & 100 times one and 100 times two, etc.
    sum += 74;  // 9 times 'hundred' and 'one thousand'
}

int main() {
    unsigned sum = 0;
    calculate(sum);
    cout << sum;
    return 0;
}