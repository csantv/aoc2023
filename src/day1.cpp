#include "solution.hpp"
#include "libs.hpp"
#include <cctype>

void Solution::day1p1()
{
    std::string line;
    std::stringstream buffer (input);
    int total = 0;
    const int base = 10;
    while (std::getline(buffer, line)) {
        std::vector<int> numbers;
        for (char chr: line) {
            if (std::isdigit(chr) > 0) {
                numbers.push_back(chr - '0');
            }
        }
        total += numbers.front() * base + numbers.back();
    }
    std::cout << total << "\n";
}

void Solution::day1p2()
{}
