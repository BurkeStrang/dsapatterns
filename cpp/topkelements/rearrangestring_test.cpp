#include "rearrangestring.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s;
        std::string want;
    };
    std::vector<test> tests = {
        {"Example 1", "aappp", "papap"},
        {"Example 2", "Programming", "gmrPagimnor"},
        {"Example 3", "aapa", ""},
        {"Single character", "a", "a"},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("rearrange_string()", rearrange_string(tt.s), tt.want);
    }
    return t::done();
}
