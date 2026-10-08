namespace DsaPatterns.IslandTraversal;

// Any image can be represented by a 2D integer array (i.e., a matrix)
// where each cell represents the pixel value of the image.
// Flood fill algorithm takes a starting cell (i.e., a pixel) and a color.
// The given color is applied to all horizontally and vertically connected
// cells with the same color as that of the starting cell.
// Recursively, the algorithm fills cells with the new color until
// it encounters a cell with a different color than the starting cell.
// Given a matrix, a starting cell, and a color, flood fill the matrix.
//
// Example 1:
// Input: matrix =  [0,0,0,1,1]
//                  [1,0,0,1,1]
//                  [1,0,0,1,1]
// starting cell = (1, 3)
// new color = 2
// Output: new matrix = [0,0,0,2,2]
//                      [1,0,0,2,2]
//                      [1,0,0,2,2]
//
// Example 2:
// Input: matrix =  [0,0,0,1,1]
//                  [1,0,0,1,1]
//                  [1,0,0,1,1]
//                  [1,0,1,1,1]
// starting cell = (3, 2)
// new color = 5
// Output: new matrix = [0,0,0,5,5]
//                      [1,0,0,5,5]
//                      [1,0,0,5,5]
//                      [1,0,5,5,5]
//
// Constraints:
// m == matrix.length
// n == - m == matrix[i].length
// 1 <= m, n <= 50
// 0 <= - m == matrix[i][j], color < 216
// 0 <= x < m
// 0 <= y < n

internal static class FloodFill
{
    private static readonly int[][] Moves =
    [
        [1, 0],
        [-1, 0],
        [0, 1],
        [0, -1],
    ];

    internal static int[][] Fill(int[][] matrix, int x, int y, int newColor)
    {
        if (matrix.Length < x || matrix[0].Length < y)
        {
            return matrix;
        }

        if (matrix[x][y] == 1)
        {
            FloodFillDfs(matrix, x, y, newColor);
        }

        return matrix;
    }

    private static void FloodFillDfs(int[][] matrix, int x, int y, int newColor)
    {
        int m = matrix.Length;
        int n = matrix[0].Length;
        matrix[x][y] = newColor;

        foreach (int[] move in Moves)
        {
            int mx = x + move[0];
            int my = y + move[1];
            bool matched =
                mx >= 0 && mx < m && my >= 0 && my < n && matrix[mx][my] == 1;
            if (matched)
            {
                FloodFillDfs(matrix, mx, my, newColor);
            }
        }
    }
}
