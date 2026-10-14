#include "insertinterval.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<Interval> intervals;
        Interval new_interval;
        std::vector<Interval> want;
    };
    std::vector<test> tests = {
        {"Example 1",
         {{1, 3}, {5, 7}, {8, 12}},
         {4, 6},
         {{1, 3}, {4, 7}, {8, 12}}},
        {"Example 2", {{1, 3}, {5, 7}, {8, 12}}, {4, 10}, {{1, 3}, {4, 12}}},
        {"Example 3", {{2, 3}, {5, 7}}, {1, 4}, {{1, 4}, {5, 7}}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("insert()", insert(tt.intervals, tt.new_interval), tt.want);
    }
    return t::done();
}
