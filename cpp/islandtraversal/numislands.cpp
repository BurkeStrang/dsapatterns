#include "islandtraversal/shared.hpp"

#include <vector>

// Given a 2D array (i.e., a matrix) containing only 1s (land) and 0s (water),
// count the number of islands in it.
//
// An island is a connected set of 1s (land) and is surrounded by either an edge
// or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically
// (not diagonally).
//
// Example 1
// Input: matrix = [1,1,1,0,0],
// 								 [0,1,0,0,1],
// 								 [0,0,1,1,0],
// 								 [0,0,1,0,0],
// 								 [0,0,1,0,0]
// Output: 3
//
// Example 2
// Input: matrix = [1,1,0,0,0],
// 								 [0,1,0,0,0],
// 								 [0,1,0,0,0],
// 								 [0,1,0,0,0],
// Output: 1
//
// Image
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is '0' or '1'.

// visit_island_dfs performs a depth-first search to visit all parts of an
// island
void visit_island_dfs(std::vector<std::vector<int>> &matrix, int x, int y)
{
    if (!in_bounds(matrix, x, y))
    {
        return; // return, if it is not a valid cell
    }
    if (matrix[x][y] == 0)
    {
        return; // return, if it is a water cell
    }

    // mark the cell visited by making it a water cell
    matrix[x][y] = 0;

    // recursively visit all neighboring cells (horizontally & vertically)
    visit_island_dfs(matrix, x + 1, y); // lower cell
    visit_island_dfs(matrix, x - 1, y); // upper cell
    visit_island_dfs(matrix, x, y + 1); // right cell
    visit_island_dfs(matrix, x, y - 1); // left cell
}

int count_islands(std::vector<std::vector<int>> &matrix)
{
    int rows = std::ssize(matrix);
    int cols = std::ssize(matrix[0]);
    int total_islands = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // only if the cell is a land
            if (matrix[i][j] == 1)
            {
                // we have found an island
                total_islands++;
                visit_island_dfs(matrix, i, j);
            }
        }
    }

    return total_islands;
}
