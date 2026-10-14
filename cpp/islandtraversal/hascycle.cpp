#include "islandtraversal/shared.hpp"

#include <vector>

// You are given a 2D matrix containing different characters,
// you need to find if there exists any cycle consisting of the same character
// in the matrix.
// A cycle is a path in the matrix that starts and ends at the same cell and has
// four or more cells.
// From a given cell,
// you can move to one of the cells adjacent to it - in one of the four
// directions
// (up, down, left, or right), if it has the same character value of the current
// cell.
// Write a function to find if the matrix has a cycle.

bool dfs_cycle(const std::vector<std::vector<char>> &matrix,
               std::vector<std::vector<bool>> &visited, int x, int y,
               int prev_x, int prev_y, char org_char)
{
    if (!in_bounds(matrix, x, y) || matrix[x][y] != org_char)
    {
        return false;
    }

    if (visited[x][y])
    {
        return true;
    }

    visited[x][y] = true;

    // visit every neighbor except the cell we just came from
    if (x + 1 != prev_x && dfs_cycle(matrix, visited, x + 1, y, x, y, org_char))
    {
        return true;
    }
    if (x - 1 != prev_x && dfs_cycle(matrix, visited, x - 1, y, x, y, org_char))
    {
        return true;
    }
    if (y + 1 != prev_y && dfs_cycle(matrix, visited, x, y + 1, x, y, org_char))
    {
        return true;
    }
    if (y - 1 != prev_y && dfs_cycle(matrix, visited, x, y - 1, x, y, org_char))
    {
        return true;
    }

    return false;
}

bool has_cycle(const std::vector<std::vector<char>> &matrix)
{
    int rows = std::ssize(matrix);
    int cols = std::ssize(matrix[0]);
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (dfs_cycle(matrix, visited, i, j, i, j, matrix[i][j]))
            {
                return true;
            }
        }
    }
    return false;
}
