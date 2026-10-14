#include "complementbase10.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        int num;
        int want;
    };
    std::vector<test> tests = {
        // number: 5 (binary 101) -> complement: 2 (binary 010)
        {"Example 1", 5, 2},
        // number: 7 (binary 111) -> complement: 0 (binary 000)
        {"Example 2", 7, 0},
        // number: 10 (binary 1010) -> complement: 5 (binary 0101)
        {"Example 3", 10, 5},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("bitwise_complement()", bitwise_complement(tt.num), tt.want);
    }
    return t::done();
}
