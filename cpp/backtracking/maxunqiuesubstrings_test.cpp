#include "maxunqiuesubstrings.cpp"

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
        {"Example 1", "ababccc", 5},
        {"Example 2", "aba", 2},
        {"Example 3", "aa", 1},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("max_unique_split()", max_unique_split(tt.s), tt.want);
    }
    return t::done();
}
