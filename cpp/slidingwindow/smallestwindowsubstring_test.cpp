#include "smallestwindowsubstring.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s;
        std::string pattern;
        std::string want;
    };
    std::vector<test> tests = {
        {"Example 1", "aabdec", "abc", "abdec"},
        {"Example 2", "aabdec", "abac", "aabdec"},
        {"Example 3", "abdbca", "abc", "bca"},
        {"Example 4", "adcad", "abc", ""},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_substring()", find_substring(tt.s, tt.pattern), tt.want);
    }
    return t::done();
}
