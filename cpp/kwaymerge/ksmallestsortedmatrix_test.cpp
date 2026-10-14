#include "ksmallestsortedmatrix.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<int>> matrix;
        int k;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {{2, 6, 8}, {3, 7, 10}, {5, 7, 8}}, 5, 7},
        {"Smaller numbers further down",
         {{1, 20, 30}, {2, 21, 31}, {3, 22, 32}},
         3,
         3},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_kth_smallest_point()",
                 find_kth_smallest_point(tt.matrix, tt.k), tt.want);
    }
    return t::done();
}
