#include "nextgreaterelement.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums1;
        std::vector<int> nums2;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", {4, 2, 6}, {6, 2, 4, 5, 3, 7}, {5, 4, 7}},
        {"Example 2", {9, 7, 1}, {1, 7, 9, 5, 4, 3}, {-1, 9, 7}},
        {"Example 3", {5, 12, 3}, {12, 3, 5, 4, 10, 15}, {10, 15, 5}},
        {"No greater element", {8}, {8, 7, 6}, {-1}},
        {"All increasing", {1, 2, 3}, {1, 2, 3, 4}, {2, 3, 4}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("next_greater_element()",
                 next_greater_element(tt.nums1, tt.nums2), tt.want);
    }
    return t::done();
}
