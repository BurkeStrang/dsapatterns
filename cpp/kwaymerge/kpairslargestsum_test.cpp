#include "kpairslargestsum.cpp"

#include "testing/testing.hpp"

int main()
{
    // the pairs come back with the smallest sum first; pairs with the same
    // sum come back in the order of their numbers
    struct test
    {
        std::string name;
        std::vector<int> nums1;
        std::vector<int> nums2;
        int k;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Example 1", {9, 8, 2}, {6, 3, 1}, 3, {{9, 3}, {8, 6}, {9, 6}}},
        {"Example 2", {5, 2, 1}, {2, -1}, 3, {{2, 2}, {5, -1}, {5, 2}}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_k_largest_pairs()",
                 find_k_largest_pairs(tt.nums1, tt.nums2, tt.k), tt.want);
    }
    return t::done();
}
