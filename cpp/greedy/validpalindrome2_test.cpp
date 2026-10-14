#include "validpalindrome2.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string input;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1", "racecar", true},
        {"Example 2", "abeccdeba", true},
        {"Example 3", "abcdef", false},
        {"Empty string", "", true},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("is_palindrome_possible()", is_palindrome_possible(tt.input),
                 tt.want);
    }
    return t::done();
}
