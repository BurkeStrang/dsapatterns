#include "rightviewbinarytree.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", {1, 3, 7}},
        {"Example 2", "[12, 7, 1, null, 9, 10, 5, null, 3]", {12, 1, 5, 3}},
        {"Example 3", "[8, 4, 9, 3, null, null, 10, 2]", {8, 9, 10, 2}},
        {"Empty tree", "[]", {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("right_view()", right_view(tree(tt.root)), tt.want);
    }
    return t::done();
}
