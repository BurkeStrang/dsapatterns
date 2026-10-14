#include "avg.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name; // description of this test case
        // Named input parameters for target function.
        int k;
        std::vector<int> arr;
        std::vector<double> want;
    };
    std::vector<test> tests = {
        {"basic case",
         5,
         {1, 3, 2, 6, -1, 4, 1, 8, 2},
         {2.2, 2.8, 2.4, 3.6, 2.8}},
        {"window size 1", 1, {5, 10, 15}, {5.0, 10.0, 15.0}},
        {"window size equals array length", 4, {2, 4, 6, 8}, {5.0}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<double> got = find_averages(tt.k, tt.arr);
        t::check_near("find_averages()", got, tt.want);
    }
    return t::done();
}
