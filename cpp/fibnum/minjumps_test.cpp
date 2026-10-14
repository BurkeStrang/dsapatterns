#include "minjumps.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> jumps;
        std::optional<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", {2, 1, 1, 1, 4}, 3},
        {"Example 2", {1, 1, 3, 6, 9, 3, 0, 1, 3}, 4},
        {"Blocked by a zero", {1, 0, 2}, std::nullopt},
        {"Single element", {0}, 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("count_min_jumps()", count_min_jumps(tt.jumps), tt.want);
    }
    return t::done();
}
