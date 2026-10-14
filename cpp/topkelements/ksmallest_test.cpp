#include "ksmallest.cpp"

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
        {"Example 1", {1, 5, 12, 2, 11, 5}, 3, 5},
        {"Example 2", {1, 5, 12, 2, 11, 5}, 4, 5},
        {"Example 3", {5, 12, 11, -1, 12}, 3, 11},
        {"Example 4", {1, 5, 12, 2, 11, 5}, 1, 1},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_kth_smallest_number()",
                 find_kth_smallest_number(tt.nums, tt.k), tt.want);
    }
    return t::done();
}
