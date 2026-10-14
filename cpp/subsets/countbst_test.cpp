#include "countbst.cpp"

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
        {"Example 1", 2, 2},
        {"Example 2", 3, 5},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("count_trees()", count_trees(tt.n), tt.want);
    }
    return t::done();
}
