#include "balanceparentheses.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        int num;
        std::vector<std::string> want;
    };
    std::vector<test> tests = {
        {"example 1", 2, {"(())", "()()"}},
        {"example 2", 3, {"((()))", "(()())", "(())()", "()(())", "()()()"}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("generate_valid_parentheses()",
                 generate_valid_parentheses(tt.num), tt.want);
    }
    return t::done();
}
