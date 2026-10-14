#include "islandtraversal/shared.hpp"

#include <vector>

// You are given a 2D matrix containing only 1s (land) and 0s (water).
// An island is a connected set of 1s (land) and is surrounded by either an edge
// or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically
// (not diagonally).
// There are no lakes on the island, so the water inside the island is not
// connected to the water around it.
// A cell is a square with a side length of 1.
// The given matrix has only one island, write a function to find the perimeter
// of that island.

int dfs(const std::vector<std::vector<int>> &matrix,
        std::vector<std::vector<bool>> &visited, int x, int y)
{
    if (!in_bounds(matrix, x, y))
    {
        // returning 1, since this a boundary cell initiated this DFS call
        return 1;
    }
    if (matrix[x][y] == 0)
    {
        // returning 1, because of the shared side b/w a water and a land cell
        return 1;
    }
    if (visited[x][y])
    {
        return 0; // we have already taken care of this cell
    }

    visited[x][y] = true; // mark the cell visited

    int edge_count = 0;
    // recursively visit all neighboring cells (horizontally & vertically)
    edge_count += dfs(matrix, visited, x + 1, y); // lower cell
    edge_count += dfs(matrix, visited, x - 1, y); // upper cell
    edge_count += dfs(matrix, visited, x, y + 1); // right cell
    edge_count += dfs(matrix, visited, x, y - 1); // left cell

    return edge_count;
}

int find_island_perimeter(const std::vector<std::vector<int>> &matrix)
{
    int rows = std::ssize(matrix);
    int cols = std::ssize(matrix[0]);
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // only if the cell is a land and not visited
            if (matrix[i][j] == 1 && !visited[i][j])
            {
                return dfs(matrix, visited, i, j);
            }
        }
    }
    return 0;
}
