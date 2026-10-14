#include "longestpalindrome.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s;
        int want;
    };
    std::vector<test> tests = {
        {"applepie", "applepie", 5}, {"aabbcc", "aabbcc", 6},
        {"bananas", "bananas", 5},   {"single character", "a", 1},
        {"all unique", "abcdef", 1}, {"all pairs", "aabb", 4},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("longest_palindrome()", longest_palindrome(tt.s), tt.want);
    }
    return t::done();
}
