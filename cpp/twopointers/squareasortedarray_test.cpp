#include "squareasortedarray.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", {-2, -1, 0, 2, 3}, {0, 1, 4, 4, 9}},
        {"Example 2", {-3, -1, 0, 1, 2}, {0, 1, 1, 4, 9}},
        {"zero", {0}, {0}},
        {"single negative", {-1}, {1}},
        {"all positive", {1, 2, 3}, {1, 4, 9}},
        {"all negative", {-4, -3, -2, -1}, {1, 4, 9, 16}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("make_squares()", make_squares(tt.arr), tt.want);
    }
    return t::done();
}
