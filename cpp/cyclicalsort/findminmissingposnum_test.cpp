#include "findminmissingposnum.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {-3, 1, 5, 4, 2}, 3},
        {"Example 2", {3, -2, 0, 1, 2}, 4},
        {"Example 3", {3, 2, 5, 1}, 4},
        {"Example 4", {33, 37, 5}, 1},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_mis()", find_mis(tt.nums), tt.want);
    }
    return t::done();
}
