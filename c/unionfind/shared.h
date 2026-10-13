// Shared helpers for the union find problems.
#ifndef DSAPATTERNS_UNIONFIND_SHARED_H
#define DSAPATTERNS_UNIONFIND_SHARED_H

#include <stdbool.h>
#include <stdlib.h>

// UnionFind keeps track of which set every element belongs to. Each set is a
// tree, and the root of the tree stands for the whole set.
typedef struct
{
    int *parent;
    int *rank;
    int size;
} UnionFind;

// uf_new makes size sets, each holding one element. Free it with uf_free.
static inline UnionFind uf_new
(
    int size
)
{
    UnionFind uf = {
        .parent = malloc((size_t)size * sizeof(int)),
        .rank = calloc((size_t)size, sizeof(int)),
        .size = size,
    };
    for (int i = 0; i < size; i++)
    {
        uf.parent[i] = i;
    }
    return uf;
}

// uf_find returns the root of the set that x belongs to.
static inline int uf_find
(
    UnionFind *uf,
    int x
)
{
    if (uf->parent[x] != x)
    {
        uf->parent[x] = uf_find(uf, uf->parent[x]); // Path compression
    }
    return uf->parent[x];
}

// uf_union merges the sets that x and y belong to.
static inline void uf_union
(
    UnionFind *uf,
    int x,
    int y
)
{
    int root_x = uf_find(uf, x);
    int root_y = uf_find(uf, y);

    if (root_x == root_y)
    {
        return;
    }

    // Union by rank: hang the shorter tree under the taller one
    if (uf->rank[root_x] < uf->rank[root_y])
    {
        uf->parent[root_x] = root_y;
    }
    else if (uf->rank[root_x] > uf->rank[root_y])
    {
        uf->parent[root_y] = root_x;
    }
    else
    {
        uf->parent[root_y] = root_x;
        uf->rank[root_x]++;
    }
}

// uf_connected reports whether x and y are in the same set.
static inline bool uf_connected
(
    UnionFind *uf,
    int x,
    int y
)
{
    return uf_find(uf, x) == uf_find(uf, y);
}

static inline void uf_free
(
    UnionFind *uf
)
{
    free(uf->parent);
    free(uf->rank);
    *uf = (UnionFind){0};
}

#endif
