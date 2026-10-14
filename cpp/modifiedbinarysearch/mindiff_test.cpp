#include "mindiff.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        int key;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {4, 6, 10}, 7, 6},
        {"Example 2", {4, 6, 10}, 4, 4},
        {"Example 3", {1, 3, 8, 10, 15}, 12, 10},
        {"Example 4", {4, 6, 10}, 17, 10},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("search_min_diff()", search_min_diff(tt.arr, tt.key), tt.want);
    }
    return t::done();
}
