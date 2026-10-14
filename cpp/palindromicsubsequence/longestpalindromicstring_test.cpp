#include "longestpalindromicstring.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string st;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", "abdbca", 3},
        {"Example 2", "cddpd", 3},
        {"Example 3", "pqr", 1},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_lp_string_length()", find_lp_string_length(tt.st),
                 tt.want);
    }
    return t::done();
}
