#include "longestpalindromicssubsequence.cpp"

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
        {"Example 1", "abdbca", 5},
        {"Example 2", "cddpd", 3},
        {"Example 3", "pqr", 1},
        {"Empty string", "", 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_lps_length()", find_lps_length(tt.st), tt.want);
    }
    return t::done();
}
