#include "bitonicarraymax.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 3, 8, 12, 4, 2}, 12},
        {"Example 2", {3, 8, 3, 1}, 8},
        {"Example 3", {1, 3, 8, 12}, 12},
        {"Example 4", {10, 9, 8}, 10},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_max_in_bitonic_array()",
                 find_max_in_bitonic_array(tt.arr), tt.want);
    }
    return t::done();
}
