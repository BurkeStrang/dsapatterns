#include "numislands.cpp"

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
        {"three islands",
         {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}},
         3},
        {"no islands", {{0, 0, 0}, {0, 0, 0}}, 0},
        {"all land", {{1, 1}, {1, 1}}, 1},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        t::check("count_islands()", count_islands(tt.matrix), tt.want);
    }
    return t::done();
}
