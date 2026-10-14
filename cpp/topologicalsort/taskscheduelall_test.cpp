#include "taskscheduelall.cpp"

#include "testing/testing.hpp"

#include <algorithm>
#include <string>

int main()
{
    // want lists every valid ordering; they can come back in any order
    struct test
    {
        std::string name;
        int tasks;
        std::vector<std::array<int, 2>> prerequisites;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Example 1: two orderings",
         4,
         {{3, 2}, {3, 0}, {2, 0}, {2, 1}},
         {{3, 2, 0, 1}, {3, 2, 1, 0}}},
        {"Example 2: one ordering", 3, {{0, 1}, {1, 2}}, {{0, 1, 2}}},
        {"Example 3: thirteen orderings",
         6,
         {{2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1, 3}},
         {{0, 1, 4, 3, 2, 5},
          {0, 1, 3, 4, 2, 5},
          {0, 1, 3, 2, 4, 5},
          {0, 1, 3, 2, 5, 4},
          {1, 0, 3, 4, 2, 5},
          {1, 0, 3, 2, 4, 5},
          {1, 0, 3, 2, 5, 4},
          {1, 0, 4, 3, 2, 5},
          {1, 3, 0, 2, 4, 5},
          {1, 3, 0, 2, 5, 4},
          {1, 3, 0, 4, 2, 5},
          {1, 3, 2, 0, 5, 4},
          {1, 3, 2, 0, 4, 5}}},
        {"No prerequisites: every arrangement",
         3,
         {},
         {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}}},
        {"Cyclic prerequisites: no ordering", 3, {{0, 1}, {1, 2}, {2, 0}}, {}},
        {"No tasks", 0, {}, {}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        std::vector<std::vector<int>> got =
            print_orders(tt.tasks, tt.prerequisites);
        std::ranges::sort(got);
        std::ranges::sort(tt.want);
        t::check("print_orders()", got, tt.want);
    }
    return t::done();
}
