#include "maxareaisland.cpp"

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
        {"two islands",
         {{0, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 1}},
         4},
        {"no island", {{0, 0, 0}, {0, 0, 0}}, 0},
        {"multiple islands", {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 0, 0, 1}}, 2},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("max_area_of_island()", max_area_of_island(tt.matrix),
                 tt.want);
    }
    return t::done();
}
