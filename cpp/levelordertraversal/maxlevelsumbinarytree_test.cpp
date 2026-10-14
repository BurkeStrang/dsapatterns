#include "maxlevelsumbinarytree.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        int want;
    };
    std::vector<test> tests = {
        {"Example 1", "[1, 20, 3, 4, 5, null, 8]", 2},
        {"Example 2", "[10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]", 3},
        {"Example 3", "[5, 6, 7, 8, null, null, 9, 10]", 3},
        {"Single node", "[42]", 1},
        {"Negative values", "[-1, -2, -3]", 1},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("max_level_sum()", max_level_sum(tree(tt.root)), tt.want);
    }
    return t::done();
}
