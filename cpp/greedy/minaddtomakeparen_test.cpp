#include "minaddtomakeparen.cpp"

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
        {"Example 1", "(()", 1},
        {"Example 2", "))((", 4},
        {"Example 3", "(()())(", 1},
        {"Already valid", "()()", 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("min_add_to_make_valid()", min_add_to_make_valid(tt.s),
                 tt.want);
    }
    return t::done();
}
