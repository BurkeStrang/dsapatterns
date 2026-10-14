#include "mergesimiliaritems.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::array<int, 2>> items1;
        std::vector<std::array<int, 2>> items2;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Example 1",
         {{1, 2}, {4, 3}},
         {{2, 1}, {4, 3}, {3, 4}},
         {{1, 2}, {2, 1}, {3, 4}, {4, 6}}},
        {"Example 2", {{5, 5}}, {{5, 10}}, {{5, 15}}},
        {"Example 3", {{1, 1}, {2, 2}}, {{3, 3}}, {{1, 1}, {2, 2}, {3, 3}}},
        {"Unsorted input",
         {{9, 1}, {2, 2}},
         {{5, 3}, {2, 4}},
         {{2, 6}, {5, 3}, {9, 1}}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("merge_similar_items()",
                 merge_similar_items(tt.items1, tt.items2), tt.want);
    }
    return t::done();
}
