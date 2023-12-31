#include "solution.hpp"
#include <chrono>
#include <iostream>

auto main(int argc, char *argv[]) -> int
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    if (argc < 2) {
        return 1;
    }
    auto time1 = high_resolution_clock::now();
    Solution sol (argv[1]);
    sol.day3p1();
    auto time2 = high_resolution_clock::now();

    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = time2 - time1;

    std::cout << ms_double.count() << "ms\n";
    return 0;
}
