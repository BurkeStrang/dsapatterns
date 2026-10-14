#include "zigzagtraversal.cpp"

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
        {"Example 1", "[1, 2, 3, 4, 5, null, 6]", {{1}, {3, 2}, {4, 5, 6}}},
        {"Example 2",
         "[7, 4, 8, 2, 5, null, 9, null, 3]",
         {{7}, {8, 4}, {2, 5, 9}, {3}}},
        {"Single node", "[42]", {{42}}},
        {"Empty tree", "[]", {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        t::check("traverse_zig_zag()", traverse_zig_zag(tree(tt.root)),
                 tt.want);
    }
    return t::done();
}
