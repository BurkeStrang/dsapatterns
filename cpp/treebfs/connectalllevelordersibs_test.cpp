#include "connectalllevelordersibs.cpp"

#include "testing/testing.hpp"

// flatten_next walks the tree using next pointers and returns the values in
// order.
std::vector<int> flatten_next(const TreeNode *root)
{
    std::vector<int> result;
    for (const TreeNode *node = root; node != nullptr; node = node->next)
    {
        result.push_back(node->value);
    }
    return result;
}

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        std::vector<int> want;
    };
    std::vector<test> tests = {
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", {1, 2, 3, 4, 5, 6, 7}},
        {"Example 2", "[12, 7, 1, 9, null, 10, 5]", {12, 7, 1, 9, 10, 5}},
        {"Empty tree", "[]", {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        TreeNode *root = tree(tt.root);
        connect_all(root);
        t::check("connect_all()", flatten_next(root), tt.want);
    }
    return t::done();
}
