#include "maxsubarrayonesreplace.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        int k;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2, 6},
        {"Example 2", {0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3, 9},
        {"Example 3", {1, 0, 0, 1, 1, 0, 1, 1}, 2, 6},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("max_ones_length()", max_ones_length(tt.arr, tt.k), tt.want);
    }
    return t::done();
}
