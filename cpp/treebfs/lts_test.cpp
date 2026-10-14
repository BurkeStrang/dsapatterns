#include "lts.cpp"

#include "testing/testing.hpp"

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Example 1", "[1, 2, 3, 4, 5, null, 6]", {{1}, {2, 3}, {4, 5, 6}}},
        {"Single node", "[42]", {{42}}},
        {"Empty tree", "[]", {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("traverse_basic()", traverse_basic(tree(tt.root)), tt.want);
    }
    return t::done();
}
