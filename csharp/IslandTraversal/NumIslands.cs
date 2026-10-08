namespace DsaPatterns.IslandTraversal;

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
//                                  [0,1,0,0,1],
//                                  [0,0,1,1,0],
//                                  [0,0,1,0,0],
//                                  [0,0,1,0,0]
// Output: 3
//
// Example 2
// Input: matrix = [1,1,0,0,0],
//                                  [0,1,0,0,0],
//                                  [0,1,0,0,0],
//                                  [0,1,0,0,0],
// Output: 1
//
// Image
// Constraints:
// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 300
// matrix[i][j] is '0' or '1'.

internal static class NumIslands
{
    internal static int CountIslands(int[][] matrix)
    {
        int rows = matrix.Length;
        int cols = matrix[0].Length;
        int totalIslands = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 1) // only if the cell is a land
                {
                    // we have found an island
                    totalIslands++;
                    VisitIslandDfs(matrix, i, j);
                }
            }
        }

        return totalIslands;
    }

    // VisitIslandDfs performs a depth-first search to visit all parts of an
    // island
    private static void VisitIslandDfs(int[][] matrix, int x, int y)
    {
        if (x < 0 || x >= matrix.Length || y < 0 || y >= matrix[0].Length)
        {
            return; // return, if it is not a valid cell
        }

        if (matrix[x][y] == 0)
        {
            return; // return, if it is a water cell
        }

        matrix[x][y] = 0; // mark the cell visited by making it a water cell

        // recursively visit all neighboring cells (horizontally & vertically)
        VisitIslandDfs(matrix, x + 1, y); // lower cell
        VisitIslandDfs(matrix, x - 1, y); // upper cell
        VisitIslandDfs(matrix, x, y + 1); // right cell
        VisitIslandDfs(matrix, x, y - 1); // left cell
    }
}
