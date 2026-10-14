#include "removekdigits.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string num;
        int k;
        std::string want;
    };
    std::vector<test> tests = {
        {"Example 1", "1432219", 3, "1219"},
        {"Example 2", "10200", 1, "200"},
        {"Example 3", "1901042", 4, "2"},
        {"Remove all digits", "10", 2, "0"},
        {"Leading zeros after removal", "100200", 1, "200"},
        {"No removal needed", "12345", 0, "12345"},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("remove_kdigits()", remove_kdigits(tt.num, tt.k), tt.want);
    }
    return t::done();
}
