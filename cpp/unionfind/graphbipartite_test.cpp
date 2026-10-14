#include "graphbipartite.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<int>> graph;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1", {{1, 3}, {0, 2}, {1, 3}, {0, 2}}, true},
        {"Example 2", {{1}, {0}, {3}, {2}}, true},
        {"Example 3", {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}}, false},
        {"No edges", {{}, {}, {}}, true},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("is_bipartite()", is_bipartite(tt.graph), tt.want);
    }
    return t::done();
}
