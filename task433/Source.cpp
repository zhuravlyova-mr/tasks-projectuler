#include <iostream>
#include <utility>
#include <future>
#include <string>
#include "profiler.h"

using namespace std;

const unsigned N = 5000000;
const int M = 500;

unsigned Euclid(long x0, long y0) {
    long temp, x = y0, y = x0 % y0;
    unsigned counter = 1;
    if (x0 != 1) {
        while (y != 0) {
            temp = x;
            x = y;
            y = temp % y;
            ++counter;
        }
        temp = 2*counter - 1;
    }
    else {
        counter = 2; //1-2, 1-3, ...1-N
        temp = 3;    //2-1, 3-1, ... N-1 
    }
    return temp;
}

int main() {
    profile::start_memory_profiling();
    profile::start_time_profiling();
    long double sum = N; // Euclid(i, i) == 1 
    long long sum_thr[M];
    long j;
    long i;
    bool flag0 = false;
    vector<future<long long>> thrs;
    int h;
    for (i = 1; i <= N-1; i += M - 1) {
        thrs.clear();
        for (int w = i; w < i + M - 1; ++w) {
            thrs.push_back(async([w, &flag0] {
                long long sumThread = 0;
                for (int j = w + 1; j <= N; ++j) {
                    sumThread += Euclid(w, j);
                }
                return sumThread;
            }));
        }
        h = 0;
        for (auto thr = thrs.begin(); thr != thrs.end(); ++thr) {
            sum_thr[h++] = thr->get();
            sum += sum_thr[h - 1];
        }
    }           
    std::cout << std::to_string(sum);
    profile::end_time_profiling();
    profile::end_memory_profiling();
    std::cout << "\nTime: " << profile::get_profiled_time().count() << " microseconds" << std::endl;
    std::cout << "Was spent: " << profile::get_profiled_memory() << " bytes of memory" << std::endl << std::endl;
    return 0;
}




