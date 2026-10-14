#include "issubarray.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        std::vector<int> sub;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 2, 3}, {2, 3}, true},
        {"Same numbers, not next to each other", {1, 2, 3}, {1, 3}, false},
        {"Longer than the array", {1, 2}, {1, 2, 3}, false},
        {"Empty subarray", {1, 2}, {}, true},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("is_subarray()", is_subarray(tt.nums, tt.sub), tt.want);
    }
    return t::done();
}
