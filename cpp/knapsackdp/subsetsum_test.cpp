#include "subsetsum.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        int sum;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 2, 3, 7}, 6, true},
        {"Example 2", {1, 2, 7, 1, 5}, 10, true},
        {"Example 3", {1, 3, 4, 8}, 6, false},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("can_partition_sum()", can_partition_sum(tt.nums, tt.sum),
                 tt.want);
    }
    return t::done();
}
