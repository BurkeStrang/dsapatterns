namespace DsaPatterns.IslandTraversal;

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

internal static class HasCycle
{
    internal static bool MatrixHasCycle(char[][] matrix)
    {
        int rows = matrix.Length;
        int cols = matrix[0].Length;
        bool[][] visited = Shared.NewVisited(rows, cols);

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (DfsCycle(matrix, visited, i, j, i, j, matrix[i][j]))
                {
                    return true;
                }
            }
        }

        return false;
    }

    private static bool DfsCycle(
        char[][] matrix,
        bool[][] visited,
        int x,
        int y,
        int prevX,
        int prevY,
        char orgChar
    )
    {
        if (
            x < 0
            || x >= matrix.Length
            || y < 0
            || y >= matrix[0].Length
            || matrix[x][y] != orgChar
        )
        {
            return false;
        }

        if (visited[x][y])
        {
            return true;
        }

        visited[x][y] = true;

        if (
            x + 1 != prevX
            && DfsCycle(matrix, visited, x + 1, y, x, y, orgChar)
        )
        {
            return true;
        }

        if (
            x - 1 != prevX
            && DfsCycle(matrix, visited, x - 1, y, x, y, orgChar)
        )
        {
            return true;
        }

        if (
            y + 1 != prevY
            && DfsCycle(matrix, visited, x, y + 1, x, y, orgChar)
        )
        {
            return true;
        }

        if (
            y - 1 != prevY
            && DfsCycle(matrix, visited, x, y - 1, x, y, orgChar)
        )
        {
            return true;
        }

        return false;
    }
}
