#include "solution.hpp"
#include "libs.hpp"
#include <cctype>

auto sum_first_last_num(const std::string& input) -> int
{
    const int base = 10;
    std::vector<int> numbers;
    for (char chr: input) {
        if (std::isdigit(chr) > 0) {
            numbers.push_back(chr - '0');
        }
    }
    if (numbers.empty()) {
        return 0;
    }
    return numbers.front() * base + numbers.back();
}

void Solution::day1p1()
{
    std::string line;
    std::stringstream buffer (input);
    int total = 0;
    while (std::getline(buffer, line)) {
        total += sum_first_last_num(line);
    }
    std::cout << total << "\n";
}

void Solution::day1p2()
{
    std::vector<std::pair<std::string_view, char>> num_map = {
        {"one", '1'},
        {"two", '2'},
        {"three", '3'},
        {"four", '4'},
        {"five", '5'},
        {"six", '6'},
        {"seven", '7'},
        {"eight", '8'},
        {"nine", '9'},
    };
    int total = 0;
    std::stringstream buffer (input);
    std::string line;
    while (std::getline(buffer, line)) {
        std::string_view view = line;
        std::string result;
        while (!view.empty()) {
            bool replaced = false;
            for (const auto& [name, chr]: num_map) {
                if (view.starts_with(name)) {
                    result.push_back(chr);
                    view.remove_prefix(name.size());
                    replaced = true;
                }
            }
            if (!replaced) {
                result.push_back(view.front());
                view.remove_prefix(1);
            }
        }
        const int values = sum_first_last_num(result);
        std::cout << values << '\n';
        total += values;
    }
    std::cout << total << "\n";
}
