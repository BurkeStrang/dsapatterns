#include "intersection.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<Interval> arr1;
        std::vector<Interval> arr2;
        std::vector<Interval> want;
    };
    std::vector<test> tests = {
        {"Example 1",
         {{1, 3}, {5, 6}, {7, 9}},
         {{2, 3}, {5, 7}},
         {{2, 3}, {5, 6}, {7, 7}}},
        {"Example 2", {{1, 3}, {5, 7}, {9, 12}}, {{5, 10}}, {{5, 7}, {9, 10}}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("intersecting_intervals()",
                 intersecting_intervals(tt.arr1, tt.arr2), tt.want);
    }
    return t::done();
}
