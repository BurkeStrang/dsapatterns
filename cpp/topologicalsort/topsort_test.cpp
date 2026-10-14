#include "topsort.cpp"

#include "testing/testing.hpp"
#include "topologicalsort/shared.hpp"

#include <string>

int main()
{
    struct test
    {
        std::string name;
        int vertices;
        std::vector<std::array<int, 2>> edges;
    };
    std::vector<test> tests = {
        {"Test Case 1", 6, {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}}},
        {"Test Case 2", 4, {{0, 1}, {1, 2}, {2, 3}}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<int> got = sort(tt.vertices, tt.edges);
        if (!is_topological_order(got, tt.vertices, tt.edges))
        {
            t::errorf("sort() = {} is not a topological order", t::str(got));
        }
    }

    t::run("A graph with a cycle has no order");
    t::check("sort()", sort(3, {{0, 1}, {1, 2}, {2, 0}}), std::vector<int>{});
    return t::done();
}
