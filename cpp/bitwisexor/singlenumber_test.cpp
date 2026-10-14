#include "singlenumber.cpp"

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
        {"Example 1", {1, 4, 2, 1, 3, 2, 3}, 4},
        {"Example 2", {7, 9, 7}, 9},
        {"Example 3", {5, 6, 7, 5, 6}, 7},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_single_number()", find_single_number(tt.arr), tt.want);
    }
    return t::done();
}
