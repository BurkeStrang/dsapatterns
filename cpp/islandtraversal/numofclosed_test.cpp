#include "numofclosed.cpp"

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
        {"one simple closed island",
         {{1, 1, 1, 1, 1},
          {1, 0, 0, 0, 1},
          {1, 0, 1, 0, 1},
          {1, 0, 0, 0, 1},
          {1, 1, 1, 1, 1}},
         1},
        {"two closed islands",
         {{1, 1, 0, 1, 0, 0},
          {1, 0, 1, 0, 0, 0},
          {1, 0, 1, 0, 1, 0},
          {1, 1, 0, 1, 0, 0}},
         2},
        {"islands touching border are NOT closed",
         {{0, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}},
         0},
        {"all land, touching every border",
         {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}},
         0},
        {"no land at all", {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 0},
        {"inner island next to one that reaches the border",
         {{1, 1, 1, 1, 1, 1},
          {1, 0, 0, 0, 0, 1},
          {1, 0, 1, 0, 0, 1},
          {0, 0, 0, 0, 1, 1},
          {1, 1, 1, 1, 1, 1}},
         1},
        // the search goes down from the top-left 1 and hits the bottom edge
        // first; the rest of the island must still be marked visited or it is
        // counted again later as a closed island
        {"open island whose search reaches the border early",
         {{0, 0, 0, 0, 0},
          {0, 1, 0, 1, 0},
          {0, 1, 1, 1, 0},
          {0, 1, 0, 0, 0},
          {0, 1, 0, 0, 0}},
         0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("count_closed_islands()", count_closed_islands(tt.matrix),
                 tt.want);
    }
    return t::done();
}
