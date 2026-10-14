#include "numofprovinces.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<std::vector<int>> is_connected;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1: Two provinces", {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}}, 2},
        {"Example 2: Three provinces", {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 3},
        {"Example 3: Two provinces",
         {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}},
         2},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_provinces()", find_provinces(tt.is_connected), tt.want);
    }
    return t::done();
}
