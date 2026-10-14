#include "subscountlessthantarget.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        int target;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {2, 5, 3, 10}, 30, 6},
        {"Example 2", {8, 2, 6, 5}, 50, 7},
        {"Example 3 (target 0)", {10, 5, 2, 6}, 0, 0},
        {"Single element < target", {1}, 2, 1},
        {"Single element >= target", {5}, 5, 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_subarray_count()",
                 find_subarray_count(tt.nums, tt.target), tt.want);
    }
    return t::done();
}
