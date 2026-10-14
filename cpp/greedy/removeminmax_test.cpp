#include "removeminmax.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> nums;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {3, 2, 5, 1, 4}, 3},
        {"Example 2", {7, 5, 6, 8, 1}, 2},
        {"Single element", {9}, 1},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("min_moves()", min_moves(tt.nums), tt.want);
    }
    return t::done();
}
