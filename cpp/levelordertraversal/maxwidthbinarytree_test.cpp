#include "maxwidthbinarytree.cpp"

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
        {"Example 1", "[1, 2, 3, 4, null, null, 5]", 4},
        {"Example 2", "[1, 2, 3, 4, null, 5, 6, null, 7]", 4},
        {"Example 3", "[1, 2, null, 3, 4, 5]", 2},
        {"Single node", "[42]", 1},
        {"Empty tree", "[]", 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("width_of_binary_tree()", width_of_binary_tree(tree(tt.root)),
                 tt.want);
    }
    return t::done();
}
