#include "numfactors.cpp"

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
        {"Example 1", 4, 4},
        {"Example 2", 5, 6},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("factors()", factors(tt.n), tt.want);
    }
    return t::done();
}
