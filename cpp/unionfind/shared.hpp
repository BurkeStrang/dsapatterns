#pragma once

#include <numeric>
#include <vector>

// UnionFind keeps track of which set every element belongs to. Each set is a
// tree, and the root of the tree stands for the whole set.
class UnionFind
{
  public:
    // Makes 'size' sets, each holding one element.
    explicit UnionFind(int size) : parent(size), rank(size)
    {
        std::iota(parent.begin(), parent.end(), 0);
    }

    // Returns the root of the set that x belongs to.
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    // Merges the sets that x and y belong to.
    void unite(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x == root_y)
        {
            return;
        }

        // Union by rank: hang the shorter tree under the taller one
        if (rank[root_x] < rank[root_y])
        {
            parent[root_x] = root_y;
        }
        else if (rank[root_x] > rank[root_y])
        {
            parent[root_y] = root_x;
        }
        else
        {
            parent[root_y] = root_x;
            rank[root_x]++;
        }
    }

    // Reports whether x and y are in the same set.
    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }

  private:
    std::vector<int> parent;
    std::vector<int> rank;
};
