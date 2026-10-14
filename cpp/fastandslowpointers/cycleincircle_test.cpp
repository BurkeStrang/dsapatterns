#include "cycleincircle.cpp"

#include "testing/testing.hpp"

#include <string>

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> arr;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1", {1, 2, -1, 2, 2}, true},
        {"Example 2", {2, 2, -1, 2}, true},
        {"Example 3", {2, 1, -1, -2}, false},
        {"No cycle, alternating directions", {1, -1, 1, -1}, false},
        {"Simple cycle", {3, 1, 2}, true},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("loop_exists()", loop_exists(tt.arr), tt.want);
    }
    return t::done();
}
