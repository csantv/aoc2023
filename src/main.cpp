#include "solution.hpp"

auto main(int argc, char *argv[]) -> int
{
    if (argc < 2) {
        return 1;
    }
    Solution sol (argv[1]);
    sol.day2p1();
    return 0;
}
