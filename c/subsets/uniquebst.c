#include <stdlib.h>

// Given a number n,
// write a function to return all structurally unique Binary Search Trees (BST),
// that can store values 1 to n?

// Example 1:
// input: 2
// output: [[1,null,2],[2,1]]

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// NodeList is a growable list of tree nodes (a NULL entry is an empty tree).
typedef struct
{
    TreeNode **items;
    int len;
    int cap;
} NodeList;

void nodelist_push
(
    NodeList *list,
    TreeNode *node
)
{
    if (list->len == list->cap)
    {
        list->cap = list->cap < 8 ? 8 : list->cap * 2;
        list->items =
            realloc(list->items, (size_t)list->cap * sizeof(list->items[0]));
    }
    list->items[list->len++] = node;
}

// UniqueTrees is the result of find_unique_trees. The trees share subtrees
// with each other, so they can't be freed one by one; all_nodes remembers
// every node that was created so unique_trees_free can free each one once.
typedef struct
{
    NodeList trees;
    NodeList all_nodes;
} UniqueTrees;

void unique_trees_free
(
    UniqueTrees *result
)
{
    for (int i = 0; i < result->all_nodes.len; i++)
    {
        free(result->all_nodes.items[i]);
    }
    free(result->all_nodes.items);
    free(result->trees.items);
    *result = (UniqueTrees){0};
}

// find_unique_trees_recursive is the recursive function to find unique trees
NodeList find_unique_trees_recursive
(
    int start,
    int end,
    NodeList *all_nodes
)
{
    NodeList result = {0};
    // base condition, return 'null' for an empty sub-tree
    // consider n=1, in this case we will have start=end=1, this means we
    // should have only one tree we will have two recursive calls,
    // find_unique_trees_recursive(1, 0) & (2, 1) both of these should return
    // 'null' for the left and the right child
    if (start > end)
    {
        nodelist_push(&result, NULL);
        return result;
    }

    for (int i = start; i <= end; i++)
    {
        // making 'i' root of the tree
        NodeList left_subtrees =
            find_unique_trees_recursive(start, i - 1, all_nodes);
        NodeList right_subtrees =
            find_unique_trees_recursive(i + 1, end, all_nodes);
        for (int l = 0; l < left_subtrees.len; l++)
        {
            for (int r = 0; r < right_subtrees.len; r++)
            {
                TreeNode *root = malloc(sizeof(TreeNode));
                root->val = i;
                root->left = left_subtrees.items[l];
                root->right = right_subtrees.items[r];
                nodelist_push(all_nodes, root);
                nodelist_push(&result, root);
            }
        }
        free(left_subtrees.items);
        free(right_subtrees.items);
    }
    return result;
}

// The caller must free the result with unique_trees_free.
UniqueTrees find_unique_trees
(
    int n
)
{
    UniqueTrees result = {0};
    if (n <= 0)
    {
        return result;
    }
    result.trees = find_unique_trees_recursive(1, n, &result.all_nodes);
    return result;
}
