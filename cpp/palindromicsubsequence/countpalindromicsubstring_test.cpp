#include "countpalindromicsubstring.cpp"

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
        {"Example 1", "abdbca", 7},
        {"Example 2", "cddpd", 7},
        {"Example 3", "pqr", 3},
        {"Empty string", "", 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_cps()", find_cps(tt.st), tt.want);
    }
    return t::done();
}
