#include "palindromicpartition.cpp"

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
        {"Example 2", "cddpd", 2},
        {"Example 3", "pqr", 2},
        {"Example 4", "pp", 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_mpp_cuts()", find_mpp_cuts(tt.st), tt.want);
    }
    return t::done();
}
