#include "islandtraversal/shared.h"

// You are given a 2D matrix containing only 1s (land) and 0s (water).
// An island is a connected set of 1s (land) and is surrounded by either an edge
// or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically
// (not diagonally).
//
// A closed island is an island that is totally surrounded by 0s (i.e., water).
// This means all horizontally and vertically connected cells of a closed island
// are water.
// This also means that, by definition, a closed island can't touch an edge
// (as then the edge cells are not connected to any water cell).
//
// Write a function to find the number of closed islands in the given matrix.
//
// Example 1
// Input: matrix = [1,1,1,1,1,1,1]
//                                  [0,0,1,0,0,0,1]
//                                  [0,0,1,0,0,1,0]
//                                  [0,0,1,0,0,1,0]
//                                  [0,0,0,0,0,0,0]
// Output: 1 Explanation: The given matrix has two islands, but only the
// highlighted island is a closed island.
// The other island is touching the boundary that's why is is not considered a
// closed island.
//
// Example 2
// Input: matrix = [1,1,1,1,1,1,1,0]
//                                  [1,0,0,0,0,1,1,0]
//                                  [0,0,1,0,1,0,1,0]
//                                  [0,0,0,0,0,0,1,0]
// Output: 2
// Explanation: The given matrix has two islands and both of them are closed
// islands.
//
// Constraints:
//
// 0 <= grid[i][j] <=1

// is_closed_island_dfs checks if the island is closed using DFS
bool is_closed_island_dfs
(
    const IntMatrix *matrix,
    Visited *visited,
    int x,
    int y
)
{
    if (x < 0 || x >= matrix->len || y < 0 || y >= matrix->rows[0].len)
    {
        return false; // returning false since the island is touching an edge
    }
    if (CELL(matrix, x, y) == 0 || SEEN(visited, x, y))
    {
        return true; // returning true as the island is surrounded by water
    }

    SEEN(visited, x, y) = true; // mark the cell visited

    bool is_closed = true;
    // recursively visit all neighboring cells (horizontally & vertically)
    // lower, upper, right, then left cell
    is_closed = is_closed && is_closed_island_dfs(matrix, visited, x + 1, y);
    is_closed = is_closed && is_closed_island_dfs(matrix, visited, x - 1, y);
    is_closed = is_closed && is_closed_island_dfs(matrix, visited, x, y + 1);
    is_closed = is_closed && is_closed_island_dfs(matrix, visited, x, y - 1);

    return is_closed;
}

int count_closed_islands
(
    const IntMatrix *matrix
)
{
    int rows = matrix->len;
    int cols = matrix->rows[0].len;
    int closed_islands = 0;
    Visited visited = visited_new(rows, cols);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // only if the cell is a land and not visited
            if (CELL(matrix, i, j) == 1 && !SEEN(&visited, i, j))
            {
                if (is_closed_island_dfs(matrix, &visited, i, j))
                {
                    closed_islands++;
                }
            }
        }
    }

    free(visited.cells);
    return closed_islands;
}
