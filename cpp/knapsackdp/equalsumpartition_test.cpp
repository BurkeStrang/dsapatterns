#include "equalsumpartition.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 2, 3, 4}, true},
        {"Example 2", {1, 1, 3, 4, 7}, true},
        {"Example 3", {2, 3, 4, 6}, false},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("can_partition()", can_partition(tt.nums), tt.want);
    }
    return t::done();
}
