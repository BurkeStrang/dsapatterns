#include "taskschedueling.cpp"

#include "testing/testing.hpp"

#include <string>

int main()
{
    struct test
    {
        std::string name;
        int tasks;
        std::vector<std::array<int, 2>> prerequisites;
        bool want;
    };
    std::vector<test> tests = {
        {"Test Case 1", 3, {{0, 1}, {1, 2}}, true},
        {"Test Case 2", 3, {{0, 1}, {1, 2}, {2, 0}}, false},
        {"Test Case 3", 4, {{0, 1}, {1, 2}, {2, 3}}, true},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("is_scheduling_possible()",
                 is_scheduling_possible(tt.tasks, tt.prerequisites), tt.want);
    }
    return t::done();
}
