#include "mergeintervals.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<Interval> intervals;
        std::vector<Interval> want;
    };
    std::vector<test> tests = {
        {"Example 1", {{1, 4}, {2, 5}, {7, 9}}, {{1, 5}, {7, 9}}},
        {"Example 2", {{6, 7}, {2, 4}, {5, 9}}, {{2, 4}, {5, 9}}},
        {"Example 3", {{1, 4}, {2, 6}, {3, 5}}, {{1, 6}}},
        {"No overlap", {{1, 2}, {3, 4}, {5, 6}}, {{1, 2}, {3, 4}, {5, 6}}},
        {"Single interval", {{1, 10}}, {{1, 10}}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("merge()", merge(tt.intervals), tt.want);
    }
    return t::done();
}
