#include "permutationsinstring.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s;
        std::string pattern;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1", "oidbcaf", "abc", true},
        {"Example 2", "odicf", "dc", false},
        {"Example 3", "bcdxabcdy", "bcdyabcdx", true},
        {"Example 4", "aaacb", "abc", true},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_permutation()", find_permutation(tt.s, tt.pattern),
                 tt.want);
    }
    return t::done();
}
