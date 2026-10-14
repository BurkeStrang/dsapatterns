#include "common/tree.hpp"

#include <vector>

// Given a number n,
// write a function to return all structurally unique Binary Search Trees (BST),
// that can store values 1 to n?

// Example 1:
// input: 2
// output: [[1,null,2],[2,1]]

// find_unique_trees_recursive is the recursive method to find unique trees
std::vector<TreeNode *> find_unique_trees_recursive(int start, int end)
{
    std::vector<TreeNode *> result;
    // base condition, return nullptr for an empty sub-tree
    // consider n=1, in this case we will have start=end=1, this means we
    // should have only one tree we will have two recursive calls,
    // find_unique_trees_recursive(1, 0) & (2, 1) both of these should return
    // nullptr for the left and the right child
    if (start > end)
    {
        result.push_back(nullptr);
        return result;
    }

    for (int i = start; i <= end; i++)
    {
        // making 'i' root of the tree
        std::vector<TreeNode *> left_subtrees =
            find_unique_trees_recursive(start, i - 1);
        std::vector<TreeNode *> right_subtrees =
            find_unique_trees_recursive(i + 1, end);
        for (TreeNode *left_tree : left_subtrees)
        {
            for (TreeNode *right_tree : right_subtrees)
            {
                // the trees share their sub-trees, like the Go version
                result.push_back(new_tree_node(i, left_tree, right_tree));
            }
        }
    }
    return result;
}

std::vector<TreeNode *> find_unique_trees(int n)
{
    if (n <= 0)
    {
        return {};
    }
    return find_unique_trees_recursive(1, n);
}
