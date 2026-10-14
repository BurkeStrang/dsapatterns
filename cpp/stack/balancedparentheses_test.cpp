#include "balancedparentheses.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string s1;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1 - balanced", "{[()]}", true},
        {"Example 2 - not balanced", "{[}]", false},
        {"Example 3 - not balanced", "(]", false},
        {"Empty string - balanced", "", true},
        {"Single type - balanced", "()[]{}", true},
        {"Single type - not balanced", "(((", false},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("valid_parentheses()", valid_parentheses(tt.s1), tt.want);
    }
    return t::done();
}
