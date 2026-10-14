#include "employeefreetime.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<Interval>> schedule;
        std::vector<Interval> want;
    };
    std::vector<test> tests = {
        {"Example 1: two employees, one free interval",
         {{{1, 3}, {5, 6}}, {{2, 3}, {6, 8}}},
         {{3, 5}}},
        {"Example 2: three employees, two free intervals",
         {{{1, 3}, {9, 12}}, {{2, 4}}, {{6, 8}}},
         {{4, 6}, {8, 9}}},
        {"Example 3: three employees, one free interval",
         {{{1, 3}}, {{2, 4}}, {{3, 5}, {7, 9}}},
         {{5, 7}}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_employee_free_time()",
                 find_employee_free_time(tt.schedule), tt.want);
    }
    return t::done();
}
