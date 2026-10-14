#include "taskscheduelorder.cpp"

#include "testing/testing.hpp"
#include "topologicalsort/shared.hpp"

#include <string>

int main()
{
    struct test
    {
        std::string name;
        int tasks;
        std::vector<std::array<int, 2>> prerequisites;
    };
    std::vector<test> tests = {
        {"Test Case 1", 6, {{2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1, 3}}},
        {"Test Case 2", 3, {{0, 1}, {1, 2}}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<int> got = find_order(tt.tasks, tt.prerequisites);
        if (!is_topological_order(got, tt.tasks, tt.prerequisites))
        {
            t::errorf("find_order() = {} is not a valid order", t::str(got));
        }
    }

    t::run("Cyclic prerequisites have no order");
    t::check("find_order()", find_order(3, {{0, 1}, {1, 2}, {2, 0}}),
             std::vector<int>{});
    return t::done();
}
