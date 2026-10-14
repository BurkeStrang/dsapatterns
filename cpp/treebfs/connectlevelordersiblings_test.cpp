#include "connectlevelordersiblings.cpp"

#include "testing/testing.hpp"

// level_order_next walks the tree using next pointers and returns the values
// level by level.
std::vector<std::vector<int>> level_order_next(const TreeNode *root)
{
    std::vector<std::vector<int>> result;
    const TreeNode *level_start = root;
    while (level_start != nullptr)
    {
        std::vector<int> level;
        const TreeNode *next_level = nullptr;
        for (const TreeNode *node = level_start; node != nullptr;
             node = node->next)
        {
            level.push_back(node->value);
            if (next_level == nullptr)
            {
                next_level = node->left != nullptr ? node->left : node->right;
            }
        }
        result.push_back(level);
        level_start = next_level;
    }
    return result;
}

int main()
{
    struct test
    {
        std::string name;
        std::string root;
        std::vector<std::vector<int>> want;
    };
    std::vector<test> tests = {
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", {{1}, {2, 3}, {4, 5, 6, 7}}},
        {"Example 2", "[12, 7, 1, 9, null, 10, 5]", {{12}, {7, 1}, {9, 10, 5}}},
        {"Empty tree", "[]", {}},
    };
    for (const test &tt : tests)
    {
        t::run(tt.name);
        TreeNode *root = tree(tt.root);
        connect(root);
        t::check("connect()", level_order_next(root), tt.want);
    }
    return t::done();
}
