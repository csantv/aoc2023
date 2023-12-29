#pragma once

#include <string>
#include <fstream>
#include <sstream>

class Solution
{
public:
    explicit Solution(const char* filename)
    {
        std::ifstream ifs (filename);
        std::stringstream buffer;
        buffer << ifs.rdbuf();
        input = buffer.str();
    }
    void day1p1();

private:
    std::string input;
};
