#include "smallestrange.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<int>> lists;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", {{1, 5, 8}, {4, 12}, {7, 8, 10}}, {4, 7}},
        {"Example 2", {{1, 9}, {4, 12}, {7, 10, 16}}, {9, 12}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_smallest_range()", find_smallest_range(tt.lists),
                 tt.want);
    }
    return t::done();
}
