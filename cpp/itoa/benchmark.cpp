#include <cmath>
#include <chrono>
#include <iostream>
#include "itoa.h"

typedef char* (*itoa_func)(int, char*);

void benchmark(itoa_func func, const char* name, int times) {
    using namespace std::chrono;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    std::cout << "Call " << name << " " << times << " times..." << std::endl;

    int n = pow(2, 31);
    char buffer[32] = {0};
    for (int i=0; i<times; ++i) {
        func(n, buffer);
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;
}

int main (int argc, char * argv[]) {
    benchmark(itoa_1, "itoa_1", 1000000);
    benchmark(itoa_2, "itoa_2", 1000000);
    return 0;
}
