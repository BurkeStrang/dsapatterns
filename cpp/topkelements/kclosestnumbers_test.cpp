#include "kclosestnumbers.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        int k;
        int x;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", {5, 6, 7, 8, 9}, 3, 7, {6, 7, 8}},
        {"Example 2", {2, 4, 5, 6, 9}, 3, 6, {4, 5, 6}},
        {"Example 3", {2, 4, 5, 6, 9}, 3, 10, {5, 6, 9}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_closest_elements()",
                 find_closest_elements(tt.arr, tt.k, tt.x), tt.want);
    }
    return t::done();
}
