#include "busroutes.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<int>> routes;
        int source;
        int target;
        int want;
    };
    std::vector<test> tests = {
        {"example 1", {{1, 2, 7}, {3, 6, 7}}, 1, 6, 2},
        {"example 2",
         {{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}},
         15,
         12,
         -1},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("num_buses_to_destination()",
                 num_buses_to_destination(tt.routes, tt.source, tt.target),
                 tt.want);
    }
    return t::done();
}
