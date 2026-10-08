#include "common/map.h"
#include "common/strbuf.h"
#include "islandtraversal/shared.h"

// You are given a 2D matrix containing only 1s (land) and 0s (water).
// An island is a connected set of 1s (land) and is surrounded by either an edge
// or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically
// (not diagonally).
// Two islands are considered the same if and only if they can be translated
// (not rotated or reflected) to equal each other.
// Write a function to find the number of distinct islands in the given matrix.

void traverse_island_dfs
(
    const IntMatrix *matrix,
    Visited *visited,
    int x,
    int y,
    StrBuf *island_traversal,
    char direction
)
{
    if (x < 0 || x >= matrix->len || y < 0 || y >= matrix->rows[0].len)
    {
        return; // return if it is not a valid cell
    }
    if (CELL(matrix, x, y) == 0 || SEEN(visited, x, y))
    {
        return; // return if it is a water cell or is visited
    }

    SEEN(visited, x, y) = true; // mark the cell visited
    strbuf_push(island_traversal, direction);

    // recursively visit all neighboring cells (horizontally & vertically)
    // down, up, right, left
    traverse_island_dfs(matrix, visited, x + 1, y, island_traversal, 'D');
    traverse_island_dfs(matrix, visited, x - 1, y, island_traversal, 'U');
    traverse_island_dfs(matrix, visited, x, y + 1, island_traversal, 'R');
    traverse_island_dfs(matrix, visited, x, y - 1, island_traversal, 'L');

    strbuf_push(island_traversal, 'B'); // back
}

int find_distinct_islands_dfs
(
    const IntMatrix *matrix
)
{
    int rows = matrix->len;
    int cols = matrix->rows[0].len;
    Visited visited = visited_new(rows, cols);
    StrMap islands_set = {0};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // only if the cell is a land and not visited
            if (CELL(matrix, i, j) == 1 && !SEEN(&visited, i, j))
            {
                StrBuf island_traversal = {0};
                // 'O' for origin
                traverse_island_dfs(matrix, &visited, i, j, &island_traversal,
                                    'O');
                strmap_set(&islands_set, island_traversal.data, 1);
                strbuf_free(&island_traversal);
            }
        }
    }

    int count = islands_set.len;
    strmap_free(&islands_set);
    free(visited.cells);
    return count;
}
