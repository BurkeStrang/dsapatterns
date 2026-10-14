#include "findpath.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        int n;
        std::vector<std::array<int, 2>> edges;
        int start;
        int end;
        bool want;
    };
    std::vector<test> tests = {
        {"path exists simple", 4, {{0, 1}, {1, 2}, {2, 3}}, 0, 3, true},
        {"no path between disconnected components",
         4,
         {{0, 1}, {2, 3}},
         0,
         3,
         false},
        {"no path with isolated nodes", 5, {{0, 1}, {3, 4}}, 0, 4, false},
        {"single node graph", 1, {}, 0, 0, true},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("valid_path()", valid_path(tt.n, tt.edges, tt.start, tt.end),
                 tt.want);
    }
    return t::done();
}
