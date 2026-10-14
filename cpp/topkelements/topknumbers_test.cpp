#include "topknumbers.cpp"

#include "testing/testing.hpp"

#include <algorithm>

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        int k;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", {3, 1, 5, 12, 2, 11}, 3, {5, 11, 12}},
        {"Example 2", {5, 12, 11, -1, 12}, 3, {11, 12, 12}},
        {"All negative", {-3, -1, -5, -12, -2, -11}, 3, {-3, -2, -1}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<int> got = find_k_largest_numbers(tt.nums, tt.k);
        // the numbers may come back in any order
        std::ranges::sort(got);
        t::check("find_k_largest_numbers()", got, tt.want);
    }
    return t::done();
}
