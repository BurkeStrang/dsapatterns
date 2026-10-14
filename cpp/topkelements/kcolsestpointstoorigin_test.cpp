#include "kcolsestpointstoorigin.cpp"

#include "testing/testing.hpp"

#include <algorithm>

int main()
{
    struct test
    {
        std::string name;
        std::vector<Point> points;
        int k;
        std::vector<Point> want;
    };
    std::vector<test> tests = {
        {"Example 1", {{1, 2}, {1, 3}}, 1, {{1, 2}}},
        {"Example 2", {{1, 3}, {3, 4}, {2, -1}}, 2, {{1, 3}, {2, -1}}},
        {"Example 3", {{1, 2}, {3, 4}, {1, -1}}, 2, {{1, -1}, {1, 2}}},
        {"Example 4", {{3, 3}, {5, -1}, {-2, 4}}, 2, {{-2, 4}, {3, 3}}},
        {"All points are the same",
         {{1, 1}, {1, 1}, {1, 1}},
         2,
         {{1, 1}, {1, 1}}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<Point> got = find_closest_points(tt.points, tt.k);
        // the points may come back in any order
        std::ranges::sort(got);
        t::check("find_closest_points()", got, tt.want);
    }
    return t::done();
}
