#include "kthlargestnuminstream.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        int k;
        int num;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {3, 1, 5, 12, 2, 11}, 4, 6, 5},
        {"Example 2", {3, 1, 5, 12, 2, 11}, 4, 13, 5},
        {"Example 3", {3, 1, 5, 12, 2, 11}, 4, 4, 4},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        KthLargest s(tt.nums, tt.k);
        t::check("add()", s.add(tt.num), tt.want);
    }
    return t::done();
}
