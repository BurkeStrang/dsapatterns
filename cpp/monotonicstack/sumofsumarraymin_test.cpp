#include "sumofsumarraymin.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        long long want;
    };
    std::vector<test> tests = {
        {"Example 1", {3, 1, 2, 4, 5}, 30},   {"Example 2", {2, 6, 5, 4}, 36},
        {"Example 3", {7, 3, 8}, 27},         {"Single element", {5}, 5},
        {"All same elements", {2, 2, 2}, 12},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("sum_subarray_mins()", sum_subarray_mins(tt.arr), tt.want);
    }
    return t::done();
}
