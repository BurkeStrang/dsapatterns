#include "conflictingappointments.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<Interval> intervals;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1: overlapping intervals", {{1, 4}, {2, 5}, {7, 9}}, false},
        {"Example 2: non-overlapping intervals",
         {{6, 7}, {2, 4}, {13, 14}, {8, 12}, {45, 47}},
         true},
        {"Example 3: overlapping intervals", {{4, 5}, {2, 3}, {3, 6}}, false},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("can_attend_all_appointments()",
                 can_attend_all_appointments(tt.intervals), tt.want);
    }
    return t::done();
}
