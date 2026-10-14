#include "flipandinvert.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<int>> arr;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Example 1",
         {{1, 0, 1}, {1, 1, 1}, {0, 1, 1}},
         {{0, 1, 0}, {0, 0, 0}, {0, 0, 1}}},
        {"Example 2",
         {{1, 1, 0, 0}, {1, 0, 0, 1}, {0, 1, 1, 1}, {1, 0, 1, 0}},
         {{1, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 1}, {1, 0, 1, 0}}},
        {"Single row", {{1, 0, 0, 1}}, {{0, 1, 1, 0}}},
    };
    for (test &tt : tests)
    {
        t::run(tt.name);
        flip_and_invert_image(tt.arr);
        t::check("flip_and_invert_image()", tt.arr, tt.want);
    }
    return t::done();
}
