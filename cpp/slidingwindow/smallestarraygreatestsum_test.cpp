#include "smallestarraygreatestsum.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        int s;
        std::vector<int> arr;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", 7, {2, 1, 5, 2, 3, 2}, 2},
        {"Example 2", 7, {2, 1, 5, 2, 8}, 1},
        {"Example 3", 8, {3, 4, 1, 1, 6}, 3},
        {"No subarray meets S", 20, {1, 2, 3, 4}, 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_min_sub_array()", find_min_sub_array(tt.s, tt.arr),
                 tt.want);
    }
    return t::done();
}
