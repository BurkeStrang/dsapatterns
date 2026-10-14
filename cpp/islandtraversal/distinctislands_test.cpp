#include "distinctislands.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<int>> matrix;
        int want;
    };
    std::vector<test> tests = {
        {"two distinct islands",
         {{1, 1, 0, 0, 0}, {1, 0, 0, 1, 1}, {0, 0, 0, 1, 1}},
         2},
        {"all islands same shape", {{1, 0, 1, 0}, {1, 0, 1, 0}}, 1},
        {"no islands", {{0, 0}, {0, 0}}, 0},
        {"single island", {{1, 1}, {1, 1}}, 1},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_distinct_islands_dfs()",
                 find_distinct_islands_dfs(tt.matrix), tt.want);
    }
    return t::done();
}
