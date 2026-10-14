#include "cyclicsort.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", {3, 1, 5, 4, 2}, {1, 2, 3, 4, 5}},
        {"Example 2", {2, 6, 4, 3, 1, 5}, {1, 2, 3, 4, 5, 6}},
        {"Example 3", {1, 5, 6, 4, 3, 2}, {1, 2, 3, 4, 5, 6}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        sort(tt.nums);
        t::check("sort()", tt.nums, tt.want);
    }
    return t::done();
}
