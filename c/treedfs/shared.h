// Shared types and helpers for the tree DFS problems.
#ifndef DSAPATTERNS_TREEDFS_SHARED_H
#define DSAPATTERNS_TREEDFS_SHARED_H

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

#endif
