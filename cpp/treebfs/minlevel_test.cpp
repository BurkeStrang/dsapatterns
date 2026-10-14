#include "minlevel.cpp"

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
        {"Example 1", "[1, 2, 3, 4, 5]", 2},
        {"Example 2", "[1, 2]", 2},
        {"Example 3", "[1, 2, 3, 4, 5, 6]", 3},
        {"Example 4", "[1]", 1},
        {"Empty tree", "[]", 0},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("find_depth()", find_depth(tree(tt.root)), tt.want);
    }
    return t::done();
}
