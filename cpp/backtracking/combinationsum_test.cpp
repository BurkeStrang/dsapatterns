#include "combinationsum.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> candidates;
        int target;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"test1", {2, 3, 6, 7}, 7, {{2, 2, 3}, {7}}},
        {"test2",
         {2, 4, 6, 8},
         10,
         {{2, 2, 2, 2, 2}, {2, 2, 2, 4}, {2, 2, 6}, {2, 4, 4}, {2, 8}, {4, 6}}},
        {"test3", {2}, 1, {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("combination_sum()", combination_sum(tt.candidates, tt.target),
                 tt.want);
    }
    return t::done();
}
