#include "largestuniquenum.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::vector<int> a;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", {5, 7, 3, 7, 5, 8}, 8},
        {"Example 2", {1, 2, 3, 2, 1, 4, 4}, 3},
        {"Example 3", {9, 9, 8, 8, 7, 7}, -1},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("largest_unique_number()", largest_unique_number(tt.a),
                 tt.want);
    }
    return t::done();
}
