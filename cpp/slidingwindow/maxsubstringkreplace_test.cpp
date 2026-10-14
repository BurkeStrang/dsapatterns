#include "maxsubstringkreplace.cpp"

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
        {"Example 1", "aabccbb", 2, 5},
        {"Example 2", "abbcb", 1, 4},
        {"Example 3", "abccde", 1, 3},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("max_length_replace()", max_length_replace(tt.s, tt.k),
                 tt.want);
    }
    return t::done();
}
