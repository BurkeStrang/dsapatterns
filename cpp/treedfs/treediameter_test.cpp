#include "treediameter.cpp"

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
        {"Single node", "[1]", 0},
        // Path: 4-2-1-3 or 5-2-1-3
        //            1
        //           / \
        //          2   3
        //         / \
        //        4   5
        {"Simple tree", "[1, 2, 3, 4, 5]", 4},
        // Path: 4-1-2-3
        //       1
        //      / \
        //     4   2
        //          \
        //           3
        {"Lopsided tree", "[1, 4, 2, null, null, null, 3]", 4},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_diameter()", find_diameter(tree(tt.root)), tt.want);
    }
    return t::done();
}
