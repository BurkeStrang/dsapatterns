#include "sortingstack.cpp"

#include "testing/testing.hpp"

int main()
{
    // the stacks are written with the bottom element first and the top last
    struct test
    {
        std::string name;
        std::vector<int> input;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", {34, 3, 31, 98, 92, 23}, {3, 23, 31, 34, 92, 98}},
        {"Example 2", {4, 3, 2, 10, 12, 1, 5, 6}, {1, 2, 3, 4, 5, 6, 10, 12}},
        {"Example 3", {20, 10, -5, -1}, {-5, -1, 10, 20}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("sort_stack()", sort_stack(tt.input), tt.want);
    }
    return t::done();
}
