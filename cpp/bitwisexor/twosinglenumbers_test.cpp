#include "twosinglenumbers.cpp"

#include "testing/testing.hpp"

#include <algorithm>

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 4, 2, 1, 3, 5, 6, 2, 3, 5}, {4, 6}},
        {"Example 2", {2, 1, 3, 2}, {1, 3}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<int> got = find_single_numbers(tt.nums);
        // the two numbers may come back in either order
        std::ranges::sort(got);
        t::check("find_single_numbers()", got, tt.want);
    }
    return t::done();
}
