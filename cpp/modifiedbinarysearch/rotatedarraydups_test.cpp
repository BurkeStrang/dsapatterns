#include "rotatedarraydups.cpp"

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
        {"Example 1", {3, 7, 3, 3, 3}, 7, 1},
        {"Example 2", {3, 3, 3, 7, 3}, 7, 3},
        {"Example 3", {3, 3, 7, 3, 3}, 7, 2},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("search_rotated_dups()", search_rotated_dups(tt.arr, tt.key),
                 tt.want);
    }
    return t::done();
}
