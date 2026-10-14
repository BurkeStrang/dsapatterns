#include "firstnonrepeatingchar.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1: apple", "apple", 0}, {"Example 2: abcab", "abcab", 2},
        {"Example 3: abab", "abab", -1},  {"Single character", "z", 0},
        {"All unique", "abcdef", 0},      {"Last unique", "aabbc", 4},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("first_uniq_char()", first_uniq_char(tt.s), tt.want);
    }
    return t::done();
}
