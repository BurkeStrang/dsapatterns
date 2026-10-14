#include "longestsubstringwithkchars.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s;
        int k;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", "araaci", 2, 4},
        {"Example 2", "araaci", 1, 2},
        {"Example 3", "cbbebi", 3, 5},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_length()", find_length(tt.s, tt.k), tt.want);
    }
    return t::done();
}
