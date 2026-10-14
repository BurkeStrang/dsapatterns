#include "bitonicarray.cpp"

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
        {"Example 1", {1, 3, 8, 4, 3}, 4, 3},
        {"Example 2", {3, 8, 3, 1}, 8, 1},
        {"Example 3", {1, 3, 8, 12}, 12, 3},
        {"Example 4", {10, 9, 8}, 10, 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("search_bitonic()", search_bitonic(tt.arr, tt.key), tt.want);
    }
    return t::done();
}
