#include "nextinterval.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<Interval> intervals;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"basic non-overlapping", {{2, 3}, {3, 4}, {5, 6}}, {1, 2, -1}},
        {"overlapping intervals", {{3, 4}, {1, 5}, {4, 6}}, {2, -1, -1}},
        {"single interval", {{1, 2}}, {-1}},
        {"self as next interval", {{1, 1}, {3, 4}}, {0, -1}},
        {"no next interval for identical",
         {{1, 2}, {1, 2}, {1, 2}},
         {-1, -1, -1}},
        {"start equals end", {{1, 2}, {2, 3}, {3, 4}}, {1, 2, -1}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_next_interval()", find_next_interval(tt.intervals),
                 tt.want);
    }
    return t::done();
}
