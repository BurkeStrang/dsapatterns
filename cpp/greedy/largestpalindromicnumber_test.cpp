#include "largestpalindromicnumber.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s;
        std::string want;
    };
    std::vector<test> tests = {
        {"Example 1", "323211444", "432141234"},
        {"Example 2", "998877", "987789"},
        {"Example 3", "54321", "5"},
        {"Only zeros", "000", "0"},
        {"Zeros in the middle", "10001", "10001"},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("largest_palindromic()", largest_palindromic(tt.s), tt.want);
    }
    return t::done();
}
