#include "minnumreachallnodes.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        int n;
        std::vector<std::array<int, 2>> edges;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", 6, {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}}, {0, 3}},
        {"Single node", 1, {}, {0}},
        {"Disconnected nodes", 3, {}, {0, 1, 2}},
        {"All nodes connected in a chain", 4, {{0, 1}, {1, 2}, {2, 3}}, {0}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_smallest_set_of_vertices()",
                 find_smallest_set_of_vertices(tt.n, tt.edges), tt.want);
    }
    return t::done();
}
