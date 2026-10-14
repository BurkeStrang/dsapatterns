#include "finddup.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 4, 4, 3, 2}, 4},
        {"Example 2", {2, 1, 3, 3, 5, 4}, 3},
        {"Example 3", {2, 4, 1, 4, 4}, 4},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_dup()", find_dup(tt.nums), tt.want);
    }
    return t::done();
}
