#include "hassumpath.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        int sum;
        bool want;
    };
    std::vector<test> tests = {
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", 10, true},
        {"Example 2", "[12, 7, 1, 9, null, 10, 5]", 23, true},
        {"Example 3", "[12, 7, 1, 9, null, 10, 5]", 16, false},
        {"Empty tree", "[]", 0, false},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("has_path()", has_path(tree(tt.root), tt.sum), tt.want);
    }
    return t::done();
}
