#include "staircase.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        int n;
        long long want;
    };
    std::vector<test> tests = {
        {"Example 1", 3, 4},
        {"Example 2", 4, 7},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("count_ways()", count_ways(tt.n), tt.want);
    }
    return t::done();
}
