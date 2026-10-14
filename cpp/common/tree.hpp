// Binary trees, as used by the tree patterns.
//
// Nodes are plain pointers, like the Go code. new_tree_node keeps every node
// it makes in a pool that lives until the program exits, so nothing has to be
// deleted.
#pragma once

#include <cstddef>
#include <deque>
#include <optional>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

struct TreeNode
{
    int value;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    // the node to the right on the same level; only the problems that
    // connect siblings set it
    TreeNode *next = nullptr;
};

// new_tree_node makes a node that stays valid until the program exits.
inline TreeNode *new_tree_node(int value, TreeNode *left = nullptr,
                               TreeNode *right = nullptr)
{
    static std::deque<TreeNode> pool;
    pool.push_back(TreeNode{value, left, right});
    return &pool.back();
}

// tree builds a binary tree from its values in level order, with `null` for
// a missing child, for example "[1, 2, 3, null, 4]". It keeps the test tables
// short.
inline TreeNode *tree(const std::string &text)
{
    std::vector<std::optional<int>> values;
    std::string inner = text.substr(1, text.size() - 2);
    std::stringstream stream(inner);
    std::string token;
    while (std::getline(stream, token, ','))
    {
        std::size_t start = token.find_first_not_of(' ');
        if (start == std::string::npos)
        {
            continue;
        }
        token = token.substr(start);
        if (token.starts_with("null"))
        {
            values.push_back(std::nullopt);
        }
        else
        {
            values.push_back(std::stoi(token));
        }
    }
    if (values.empty() || !values[0])
    {
        return nullptr;
    }

    TreeNode *root = new_tree_node(*values[0]);
    std::queue<TreeNode *> queue;
    queue.push(root);
    std::size_t i = 1;
    while (!queue.empty() && i < values.size())
    {
        TreeNode *parent = queue.front();
        queue.pop();
        if (i < values.size() && values[i])
        {
            parent->left = new_tree_node(*values[i]);
            queue.push(parent->left);
        }
        i++;
        if (i < values.size() && values[i])
        {
            parent->right = new_tree_node(*values[i]);
            queue.push(parent->right);
        }
        i++;
    }
    return root;
}
