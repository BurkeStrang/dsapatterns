#include "narraytree.cpp"

#include "testing/testing.hpp"

#include <optional>

int main()
{
    struct test
    {
        std::string name;
        std::optional<NAryNode> root;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Example 1: [1,null,2,3,4,null,5,6]",
         NAryNode{1, {{2, {{5, {}}, {6, {}}}}, {3, {}}, {4, {}}}},
         {{1}, {2, 3, 4}, {5, 6}}},
        {"Single node", NAryNode{42, {}}, {{42}}},
        {"Empty tree", std::nullopt, {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        const NAryNode *root = tt.root ? &*tt.root : nullptr;
        t::check("level_order()", level_order(root), tt.want);
    }
    return t::done();
}
