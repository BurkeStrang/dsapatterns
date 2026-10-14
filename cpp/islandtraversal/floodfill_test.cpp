#include "floodfill.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<int>> matrix;
        int x;
        int y;
        int new_color;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"basic flood fill",
         {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}},
         1,
         1,
         2,
         {{2, 2, 2}, {2, 2, 0}, {2, 0, 1}}},
        {"starting point already new color",
         {{0, 0}, {0, 1}},
         1,
         1,
         1,
         {{0, 0}, {0, 1}}},
        {"no fill when starting outside bounds",
         {{1, 1}, {1, 1}},
         3, // outside grid
         0,
         5,
         {{1, 1}, {1, 1}}},
        {"single cell matrix", {{1}}, 0, 0, 9, {{9}}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        flood_fill(tt.matrix, tt.x, tt.y, tt.new_color);
        t::check("flood_fill()", tt.matrix, tt.want);
    }
    return t::done();
}
