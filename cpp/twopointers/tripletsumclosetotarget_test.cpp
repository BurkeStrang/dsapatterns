#include "tripletsumclosetotarget.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        int target;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {-1, 0, 2, 3}, 3, 2},
        {"Example 2", {-3, -1, 1, 2}, 1, 0},
        {"Example 3", {1, 0, 1, 1}, 100, 3},
        {"Example 4", {0, 0, 1, 1, 2, 6}, 5, 4},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("search_triplet()", search_triplet(tt.arr, tt.target),
                 tt.want);
    }
    return t::done();
}
