#include "islandperimeter.cpp"

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
        // shape is a plus sign → perimeter = 12
        {"plus sign island", {{0, 1, 0}, {1, 1, 1}, {0, 1, 0}}, 12},
        {"single land cell", {{1}}, 4},
        // ends (3 sides + 3 sides) + middle (2 + 2)
        {"single row island", {{1, 1, 1, 1}}, 10},
        // 2x2 block perimeter = 8
        {"one big solid block", {{1, 1}, {1, 1}}, 8},
        // Shape:
        // 1 .
        // 1 1
        {"L-shaped island", {{1, 0}, {1, 1}}, 8},
        {"island touching border", {{1, 1, 0}, {1, 0, 0}, {1, 1, 1}}, 14},
        // A hollow square → perimeter counts both outer and inner edges
        // outer = 12, inner hole = 4 → total = 16
        {"island with a hole inside", {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, 16},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_island_perimeter()", find_island_perimeter(tt.matrix),
                 tt.want);
    }
    return t::done();
}
