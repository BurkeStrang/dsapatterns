#include "evenoddtree.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1: Valid Even-Odd Tree", "[1, 10, 4, 3, 7]", true},
        {"Example 2: Invalid Even-Odd Tree (odd values at level 1)",
         "[5, 9, 3, 12, null, null, 8]", false},
        {"Example 3: Invalid Even-Odd Tree (even values at even level)",
         "[7, 10, 2, 12, 8]", false},
        {"Single node (odd value at level 0)", "[1]", true},
        {"Single node (even value at level 0)", "[2]", false},
        {"Empty tree", "[]", true},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("is_even_odd_tree()", is_even_odd_tree(tree(tt.root)),
                 tt.want);
    }
    return t::done();
}
