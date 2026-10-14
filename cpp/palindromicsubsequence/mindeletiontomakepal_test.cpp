#include "mindeletiontomakepal.cpp"

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
        {"Example 1", "abdbca", 1},
        {"Example 2", "cddpd", 2},
        {"Example 3", "pqr", 2},
        {"Empty string", "", 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_minimum_deletions()", find_minimum_deletions(tt.st),
                 tt.want);
    }
    return t::done();
}
