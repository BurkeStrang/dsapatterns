#include "rotationcount.cpp"

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
        {"Example 1", {10, 15, 1, 3, 8}, 2},
        {"Example 2", {4, 5, 7, 9, 10, -1, 2}, 5},
        {"Example 3", {1, 3, 8, 10}, 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("count_rotations()", count_rotations(tt.arr), tt.want);
    }
    return t::done();
}
