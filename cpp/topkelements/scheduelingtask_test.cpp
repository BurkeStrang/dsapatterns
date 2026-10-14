#include "scheduelingtask.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::string> tasks;
        int k;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {"a", "a", "a", "b", "c", "c"}, 2, 7},
        {"Example 2", {"a", "b", "a"}, 3, 5},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("schedule_tasks()", schedule_tasks(tt.tasks, tt.k), tt.want);
    }
    return t::done();
}
