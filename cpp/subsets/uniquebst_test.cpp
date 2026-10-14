#include "uniquebst.cpp"

#include "testing/testing.hpp"

#include <string>

// shape writes a tree out in preorder, with '-' for a missing child, so that
// two trees with the same shape and values give the same text.
std::string shape(const TreeNode *node)
{
    if (node == nullptr)
    {
        return "-";
    }
    return std::to_string(node->value) + "(" + shape(node->left) + " " +
           shape(node->right) + ")";
}

int main()
{
    struct test
    {
        std::string name;
        int n;
        std::vector<std::string> want; // each tree in level order
    };
    std::vector<test> tests = {
        {"Example 1", 2, {"[1, null, 2]", "[2, 1]"}},
        {"Example 2",
         3,
         {"[1, null, 2, null, 3]", "[1, null, 3, 2]", "[2, 1, 3]",
          "[3, 1, null, null, 2]", "[3, 2, null, 1]"}},
        {"Nothing to build", 0, {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        std::vector<std::string> got;
        for (const TreeNode *root : find_unique_trees(tt.n))
        {
            got.push_back(shape(root));
        }
        std::vector<std::string> want;
        for (const std::string &root : tt.want)
        {
            want.push_back(shape(tree(root)));
        }
        t::check("find_unique_trees()", got, want);
    }
    return t::done();
}
