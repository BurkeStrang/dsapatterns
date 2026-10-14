#include "missingnumber.cpp"

#include "testing/testing.hpp"

#include <numeric>

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        int want;
    };
    std::vector<int> one_to_twenty(20);
    std::iota(one_to_twenty.begin(), one_to_twenty.end(), 1);
    std::vector<test> tests = {
        {"Example 1", {1, 2, 3, 5}, 4},
        {"Example 2", {1, 2, 4, 5}, 3},
        {"Example 3", one_to_twenty, 21},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_missing_number()", find_missing_number(tt.arr), tt.want);
    }
    return t::done();
}
