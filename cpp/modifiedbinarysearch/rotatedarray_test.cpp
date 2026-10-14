#include "rotatedarray.cpp"

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
        {"Example 1", {10, 15, 1, 3, 8}, 15, 1},
        {"Example 2", {4, 5, 7, 9, 10, -1, 2}, 10, 4},
        {"Example 3", {10, 15, 1, 3, 8}, 100, -1},
        {"Example 4", {10, 15, 1, 3, 8}, 1, 2},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("search_rotated()", search_rotated(tt.arr, tt.key), tt.want);
    }
    return t::done();
}
