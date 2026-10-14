#include "rearrangedist.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s;
        int k;
        std::string want;
    };
    std::vector<test> tests = {
        {"Example 1", "mmpp", 2, "mpmp"},
        {"Example 2", "Programming", 3, "gmrPagimnor"},
        {"Example 3", "aab", 2, "aba"},
        {"Example 4: not possible", "aappa", 3, ""},
        {"k of 1 changes nothing", "aab", 1, "aab"},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("reorganize_string()", reorganize_string(tt.s, tt.k), tt.want);
    }
    return t::done();
}
