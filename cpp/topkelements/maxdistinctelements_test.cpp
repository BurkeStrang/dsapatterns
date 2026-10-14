#include "maxdistinctelements.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        int k;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {7, 3, 5, 8, 5, 3, 3}, 2, 3},
        {"Example 2", {3, 5, 12, 11, 12}, 3, 2},
        {"Example 3", {1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2, 3},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_maximum_distinct_elements()",
                 find_maximum_distinct_elements(tt.nums, tt.k), tt.want);
    }
    return t::done();
}
