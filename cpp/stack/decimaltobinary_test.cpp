#include "decimaltobinary.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        int num;
        std::string want;
    };
    std::vector<test> tests = {
        {"Example 1", 2, "10"},
        {"Example 2", 7, "111"},
        {"Example 3", 18, "10010"},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("decimal_to_binary()", decimal_to_binary(tt.num), tt.want);
    }
    return t::done();
}
