namespace DsaPatterns.IslandTraversal;

internal static class MaxAreaIsland
{
    internal static int MaxAreaOfIsland(int[][] matrix)
    {
        int rows = matrix.Length;
        int cols = matrix[0].Length;
        int biggestIslandArea = 0;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 1) // only if the cell is a land
                {
                    // we have found an island
                    biggestIslandArea = Math.Max(
                        biggestIslandArea,
                        GetIslandArea(matrix, i, j)
                    );
                }
            }
        }

        return biggestIslandArea;
    }

    private static int GetIslandArea(int[][] matrix, int x, int y)
    {
        if (x < 0 || x >= matrix.Length || y < 0 || y >= matrix[0].Length)
        {
            return 0; // return, if it is not a valid cell
        }

        if (matrix[x][y] == 0)
        {
            return 0; // return, if it is a water cell
        }

        matrix[x][y] = 0; // mark the cell visited by making it a water cell

        int area = 1; // counting the current cell
        // recursively visit all neighboring cells (horizontally & vertically)
        area += GetIslandArea(matrix, x + 1, y); // lower cell
        area += GetIslandArea(matrix, x - 1, y); // upper cell
        area += GetIslandArea(matrix, x, y + 1); // right cell
        area += GetIslandArea(matrix, x, y - 1); // left cell

        return area;
    }
}
