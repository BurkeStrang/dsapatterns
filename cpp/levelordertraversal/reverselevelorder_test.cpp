#include "reverselevelorder.cpp"

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
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", {{4, 5, 6, 7}, {2, 3}, {1}}},
        {"Example 2", "[12, 7, 1, null, 9, 10, 5]", {{9, 10, 5}, {7, 1}, {12}}},
        {"Example 3",
         "[6, 5, 2, null, null, 1, 6, 3, 56, null, 3]",
         {{3, 56, 3}, {1, 6}, {5, 2}, {6}}},
        {"Empty tree", "[]", {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("traverse()", traverse(tree(tt.root)), tt.want);
    }
    return t::done();
}
