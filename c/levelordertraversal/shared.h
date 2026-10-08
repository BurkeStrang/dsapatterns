// Shared types and helpers for the level order traversal problems.
#ifndef DSAPATTERNS_LEVELORDERTRAVERSAL_SHARED_H
#define DSAPATTERNS_LEVELORDERTRAVERSAL_SHARED_H

#include "common/list.h"
#include "common/queue.h"

#include <limits.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

// TREE_NULL marks a missing child in the values given to tree_from.
#define TREE_NULL INT_MIN

// tree_from builds a binary tree from its level order values, with TREE_NULL
// for a missing child (e.g. 1, 2, 3, TREE_NULL, 4), and returns its root, or
// NULL for an empty tree. All the nodes live in one block of memory that
// starts at the root, so freeing the root frees the whole tree.
static inline TreeNode *tree_from
(
    const int *vals,
    int len
)
{
    if (len == 0 || vals[0] == TREE_NULL)
    {
        return NULL;
    }
    TreeNode *nodes = calloc((size_t)len, sizeof(TreeNode));
    int used = 0;
    nodes[used++].val = vals[0];
    // 'parent' walks the nodes in the order they were created, which is the
    // order their children appear in vals
    int parent = 0;
    int i = 1;
    while (i < len && parent < used)
    {
        if (vals[i] != TREE_NULL)
        {
            nodes[used].val = vals[i];
            nodes[parent].left = &nodes[used++];
        }
        i++;
        if (i < len && vals[i] != TREE_NULL)
        {
            nodes[used].val = vals[i];
            nodes[parent].right = &nodes[used++];
        }
        i++;
        parent++;
    }
    return nodes;
}

// node_queue_push and node_queue_pop use a Queue to hold tree nodes.
static inline void node_queue_push
(
    Queue *queue,
    TreeNode *node
)
{
    queue_push(queue, &node);
}

static inline TreeNode *node_queue_pop
(
    Queue *queue
)
{
    TreeNode *node;
    queue_pop(queue, &node);
    return node;
}

// NAryNode is a tree node with any number of children.
typedef struct NAryNode
{
    int val;
    struct NAryNode **children;
    int children_len;
} NAryNode;

// NAryTree owns the memory of an n-ary tree built by nary_tree_from.
typedef struct
{
    NAryNode *root; // NULL for an empty tree
    NAryNode *nodes;
    NAryNode **links;
} NAryTree;

// nary_tree_from builds an n-ary tree from its level order values, where
// each group of children ends with TREE_NULL
// (e.g. 1, TREE_NULL, 2, 3, 4, TREE_NULL, 5, 6).
static inline NAryTree nary_tree_from
(
    const int *vals,
    int len
)
{
    NAryTree tree = {0};
    if (len == 0 || vals[0] == TREE_NULL)
    {
        return tree;
    }
    tree.nodes = calloc((size_t)len, sizeof(NAryNode));
    tree.links = calloc((size_t)len, sizeof(NAryNode *));
    tree.root = tree.nodes;
    int used = 0;
    int links_used = 0;
    tree.nodes[used++].val = vals[0];
    int parent = 0;
    int i = 2; // skip the root and the TREE_NULL that follows it
    while (i < len && parent < used)
    {
        tree.nodes[parent].children = &tree.links[links_used];
        while (i < len && vals[i] != TREE_NULL)
        {
            tree.nodes[used].val = vals[i];
            tree.links[links_used++] = &tree.nodes[used++];
            tree.nodes[parent].children_len++;
            i++;
        }
        i++; // skip the TREE_NULL that ends this group of children
        parent++;
    }
    return tree;
}

static inline void nary_tree_free
(
    NAryTree *tree
)
{
    free(tree->nodes);
    free(tree->links);
    *tree = (NAryTree){0};
}

#endif
