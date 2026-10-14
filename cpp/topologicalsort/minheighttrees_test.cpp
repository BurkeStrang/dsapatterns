#include "minheighttrees.cpp"

#include "testing/testing.hpp"

#include <algorithm>

int main()
{
    struct test
    {
        std::string name;
        int nodes;
        std::vector<std::array<int, 2>> edges;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", 5, {{0, 1}, {1, 2}, {1, 3}, {2, 4}}, {1, 2}},
        {"Example 2", 4, {{0, 1}, {0, 2}, {2, 3}}, {0, 2}},
        {"Example 3", 4, {{0, 1}, {1, 2}, {1, 3}}, {1}},
        {"Star", 4, {{1, 0}, {1, 2}, {1, 3}}, {1}},
        {"Two centres", 6, {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}}, {3, 4}},
        {"One node", 1, {}, {0}},
        {"No nodes", 0, {}, {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<int> got = find_trees(tt.nodes, tt.edges);
        // the roots can come back in any order
        std::ranges::sort(got);
        t::check("find_trees()", got, tt.want);
    }
    return t::done();
}
