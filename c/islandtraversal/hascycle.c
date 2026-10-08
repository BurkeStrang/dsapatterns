#include "islandtraversal/shared.h"

#include <string.h>

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

bool dfs_cycle
(
    const char *const *matrix,
    int rows,
    int cols,
    Visited *visited,
    int x,
    int y,
    int prev_x,
    int prev_y,
    char org_char
)
{
    if (x < 0 || x >= rows || y < 0 || y >= cols || matrix[x][y] != org_char)
    {
        return false;
    }

    if (SEEN(visited, x, y))
    {
        return true;
    }

    SEEN(visited, x, y) = true;

    if (x + 1 != prev_x &&
        dfs_cycle(matrix, rows, cols, visited, x + 1, y, x, y, org_char))
    {
        return true;
    }

    if (x - 1 != prev_x &&
        dfs_cycle(matrix, rows, cols, visited, x - 1, y, x, y, org_char))
    {
        return true;
    }

    if (y + 1 != prev_y &&
        dfs_cycle(matrix, rows, cols, visited, x, y + 1, x, y, org_char))
    {
        return true;
    }

    if (y - 1 != prev_y &&
        dfs_cycle(matrix, rows, cols, visited, x, y - 1, x, y, org_char))
    {
        return true;
    }

    return false;
}

// matrix holds one string per row of the grid.
bool has_cycle
(
    const char *const *matrix,
    int rows
)
{
    int cols = (int)strlen(matrix[0]);
    Visited visited = visited_new(rows, cols);
    bool found = false;

    for (int i = 0; i < rows && !found; i++)
    {
        for (int j = 0; j < cols && !found; j++)
        {
            if (dfs_cycle(matrix, rows, cols, &visited, i, j, i, j,
                          matrix[i][j]))
            {
                found = true;
            }
        }
    }

    free(visited.cells);
    return found;
}
