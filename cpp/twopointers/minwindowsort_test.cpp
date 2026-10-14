#include "minwindowsort.cpp"

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
        {"Example 1", {1, 2, 5, 3, 7, 10, 9, 12}, 5},
        {"Example 2", {1, 3, 2, 0, -1, 7, 10}, 5},
        {"Example 3", {1, 2, 3}, 0},
        {"Example 4", {3, 2, 1}, 3},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("min_sort()", min_sort(tt.arr), tt.want);
    }
    return t::done();
}
