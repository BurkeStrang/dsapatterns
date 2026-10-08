#include "common/list.h"

// There are n cities. Some of them are connected in a network.
// If City A is directly connected to City B,
// and City B is directly connected to City C,
// city A is indirectly connected to City C.
//
// If a group of cities are connected directly or indirectly,
// they form a province.
// Given an n x n matrix isConnected where isConnected[i][j] = 1
// if the ith city and the jth city are directly connected,
// and isConnected[i][j] = 0 otherwise, determine the total number of provinces.
//
// Example 1:
// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Expected Output: 2
// Justification: Here, city 1 and 2 form a single provenance, and city 3 is one
// province itself.
//
// Example 2:
// Input: isConnected = [1,0,0],[0,1,0],[0,0,1]]
// Expected Output: 3
// Justification: In this scenario, no cities are connected to each other, so
// each city forms its own province.
//
// Example 3:
// Input: isConnected = [[1,0,0,1],[0,1,1,0],[0,1,1,0],[1,0,0,1]]
// Expected Output: 2
// Justification: Cities 1 and 4 form a province, and cities 2 and 3 form
// another province,
// resulting in a total of 2 provinces.
//
// Constraints:
// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]

typedef struct
{
    int *parent;
    int *rank;
} UnionFind;

UnionFind union_find_new
(
    int size
)
{
    UnionFind uf;
    uf.parent = malloc((size_t)size * sizeof(int));
    uf.rank = calloc((size_t)size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        uf.parent[i] = i;
    }
    return uf;
}

int union_find_find
(
    UnionFind *uf,
    int x
)
{
    if (uf->parent[x] != x)
    {
        uf->parent[x] = union_find_find(uf, uf->parent[x]); // Path compression
    }
    return uf->parent[x];
}

void union_find_union_set
(
    UnionFind *uf,
    int x,
    int y
)
{
    int root_x = union_find_find(uf, x);
    int root_y = union_find_find(uf, y);

    // If they are in the same set, do nothing.
    if (root_x == root_y)
    {
        return;
    }

    // Union by rank
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

int find_provinces
(
    const IntMatrix *is_connected
)
{
    int n = is_connected->len;
    UnionFind uf = union_find_new(n);
    int number_of_provinces = n;

    // Iterate over each pair of nodes and union the sets if there is a
    // connection.
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (is_connected->rows[i].items[j] == 1 &&
                union_find_find(&uf, i) != union_find_find(&uf, j))
            {
                number_of_provinces--;
                union_find_union_set(&uf, i, j);
            }
        }
    }

    free(uf.parent);
    free(uf.rank);
    return number_of_provinces;
}
