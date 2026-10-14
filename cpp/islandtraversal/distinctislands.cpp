#include "islandtraversal/shared.hpp"

#include <string>
#include <unordered_set>
#include <vector>

// You are given a 2D matrix containing only 1s (land) and 0s (water).
// An island is a connected set of 1s (land) and is surrounded by either an edge
// or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically
// (not diagonally).
// Two islands are considered the same if and only if they can be translated
// (not rotated or reflected) to equal each other.
// Write a function to find the number of distinct islands in the given matrix.

void traverse_island_dfs(const std::vector<std::vector<int>> &matrix,
                         std::vector<std::vector<bool>> &visited, int x, int y,
                         std::string &path, char direction)
{
    if (!in_bounds(matrix, x, y))
    {
        return; // return if it is not a valid cell
    }
    if (matrix[x][y] == 0 || visited[x][y])
    {
        return; // return if it is a water cell or is visited
    }

    visited[x][y] = true; // mark the cell visited
    path += direction;

    // recursively visit all neighboring cells (horizontally & vertically)
    traverse_island_dfs(matrix, visited, x + 1, y, path, 'D'); // down
    traverse_island_dfs(matrix, visited, x - 1, y, path, 'U'); // up
    traverse_island_dfs(matrix, visited, x, y + 1, path, 'R'); // right
    traverse_island_dfs(matrix, visited, x, y - 1, path, 'L'); // left

    path += 'B'; // back
}

int find_distinct_islands_dfs(const std::vector<std::vector<int>> &matrix)
{
    int rows = std::ssize(matrix);
    int cols = std::ssize(matrix[0]);
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols));
    std::unordered_set<std::string> islands_set;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // only if the cell is a land and not visited
            if (matrix[i][j] == 1 && !visited[i][j])
            {
                std::string island_traversal;
                traverse_island_dfs(matrix, visited, i, j, island_traversal,
                                    'O'); // origin
                islands_set.insert(island_traversal);
            }
        }
    }
    return std::ssize(islands_set);
}
