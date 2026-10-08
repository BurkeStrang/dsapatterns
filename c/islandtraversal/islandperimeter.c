#include "islandtraversal/shared.h"

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

int dfs
(
    const IntMatrix *matrix,
    Visited *visited,
    int x,
    int y
)
{
    if (x < 0 || x >= matrix->len || y < 0 || y >= matrix->rows[0].len)
    {
        // returning 1, since this a boundary cell initiated this DFS call
        return 1;
    }

    if (CELL(matrix, x, y) == 0)
    {
        // returning 1, because of the shared side b/w a water and a land cell
        return 1;
    }

    if (SEEN(visited, x, y))
    {
        return 0; // we have already taken care of this cell
    }

    SEEN(visited, x, y) = true; // mark the cell visited

    int edge_count = 0;
    // recursively visit all neighboring cells (horizontally & vertically)
    edge_count += dfs(matrix, visited, x + 1, y); // lower cell
    edge_count += dfs(matrix, visited, x - 1, y); // upper cell
    edge_count += dfs(matrix, visited, x, y + 1); // right cell
    edge_count += dfs(matrix, visited, x, y - 1); // left cell

    return edge_count;
}

int find_island_perimeter
(
    const IntMatrix *matrix
)
{
    int rows = matrix->len;
    int cols = matrix->rows[0].len;
    Visited visited = visited_new(rows, cols);
    int perimeter = 0;
    bool found = false;

    for (int i = 0; i < rows && !found; i++)
    {
        for (int j = 0; j < cols && !found; j++)
        {
            // only if the cell is a land and not visited
            if (CELL(matrix, i, j) == 1 && !SEEN(&visited, i, j))
            {
                perimeter = dfs(matrix, &visited, i, j);
                found = true;
            }
        }
    }

    free(visited.cells);
    return perimeter;
}
