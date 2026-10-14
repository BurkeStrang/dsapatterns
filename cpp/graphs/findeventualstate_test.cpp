#include "findeventualstate.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<int>> graph;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1: [3,4,5,6]",
         {{1, 2}, {2, 3}, {2}, {}, {5}, {6}, {}},
         {3, 4, 5, 6}},
        {"Example 2: [2,4,5,6]",
         {{1, 2}, {2, 3}, {5}, {0}, {}, {}, {4}},
         {2, 4, 5, 6}},
        {"Example 3: [0,1,2,3,4]",
         {{1, 2, 3}, {2, 3}, {3}, {}, {0, 1, 2}},
         {0, 1, 2, 3, 4}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("eventual_safe_nodes()", eventual_safe_nodes(tt.graph),
                 tt.want);
    }
    return t::done();
}
