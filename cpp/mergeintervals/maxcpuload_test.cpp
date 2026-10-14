#include "maxcpuload.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<Job> jobs;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1: overlapping jobs", {{1, 4, 3}, {2, 5, 4}, {7, 9, 6}}, 7},
        {"Example 2: non-overlapping jobs",
         {{6, 7, 10}, {2, 4, 11}, {8, 12, 15}},
         15},
        {"Example 3: all overlap", {{1, 4, 2}, {2, 4, 1}, {3, 6, 5}}, 8},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_max_cpu_load()", find_max_cpu_load(tt.jobs), tt.want);
    }
    return t::done();
}
