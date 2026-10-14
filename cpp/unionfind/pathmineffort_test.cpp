#include "pathmineffort.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<int>> heights;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}}, 1},
        {"Example 2", {{1, 2, 2}, {3, 3, 3}, {5, 3, 1}}, 2},
        {"Example 3", {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, 0},
        {"One cell", {{7}}, 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("minimum_effort_path()", minimum_effort_path(tt.heights),
                 tt.want);
    }
    return t::done();
}
