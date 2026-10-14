#include "subslessthantarget.cpp"

#include "testing/testing.hpp"

#include <algorithm>

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        int target;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Example 1", {2, 5, 3, 10}, 30, {{2}, {2, 5}, {5}, {5, 3}, {3}, {10}}},
        {"Example 2",
         {8, 2, 6, 5},
         50,
         {{8}, {8, 2}, {2}, {2, 6}, {6}, {6, 5}, {5}}},
        {"Target 0", {10, 5, 2, 6}, 0, {}},
        {"Single element < target", {1}, 2, {{1}}},
        {"Single element >= target", {5}, 5, {}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        std::vector<std::vector<int>> got = find_subarrays(tt.arr, tt.target);
        // the subarrays may come back in any order
        std::ranges::sort(got);
        std::ranges::sort(tt.want);
        t::check("find_subarrays()", got, tt.want);
    }
    return t::done();
}
