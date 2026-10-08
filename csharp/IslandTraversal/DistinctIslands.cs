using System.Text;

namespace DsaPatterns.IslandTraversal;

// You are given a 2D matrix containing only 1s (land) and 0s (water).
// An island is a connected set of 1s (land) and is surrounded by either an edge
// or 0s (water).
// Each cell is considered connected to other cells horizontally or vertically
// (not diagonally).
// Two islands are considered the same if and only if they can be translated
// (not rotated or reflected) to equal each other.
// Write a function to find the number of distinct islands in the given matrix.

internal static class DistinctIslands
{
    internal static int FindDistinctIslandsDfs(int[][] matrix)
    {
        int rows = matrix.Length;
        int cols = matrix[0].Length;
        bool[][] visited = Shared.NewVisited(rows, cols);
        HashSet<string> islandsSet = [];

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // only if the cell is a land and not visited
                if (matrix[i][j] == 1 && !visited[i][j])
                {
                    StringBuilder islandTraversal = new();
                    // 'O' for origin
                    TraverseIslandDfs(
                        matrix,
                        visited,
                        i,
                        j,
                        islandTraversal,
                        'O'
                    );
                    islandsSet.Add(islandTraversal.ToString());
                }
            }
        }

        return islandsSet.Count;
    }

    private static void TraverseIslandDfs(
        int[][] matrix,
        bool[][] visited,
        int x,
        int y,
        StringBuilder islandTraversal,
        char direction
    )
    {
        if (x < 0 || x >= matrix.Length || y < 0 || y >= matrix[0].Length)
        {
            return; // return if it is not a valid cell
        }

        if (matrix[x][y] == 0 || visited[x][y])
        {
            return; // return if it is a water cell or is visited
        }

        visited[x][y] = true; // mark the cell visited
        islandTraversal.Append(direction);

        // recursively visit all neighboring cells (horizontally & vertically)
        // down, up, right, left
        TraverseIslandDfs(matrix, visited, x + 1, y, islandTraversal, 'D');
        TraverseIslandDfs(matrix, visited, x - 1, y, islandTraversal, 'U');
        TraverseIslandDfs(matrix, visited, x, y + 1, islandTraversal, 'R');
        TraverseIslandDfs(matrix, visited, x, y - 1, islandTraversal, 'L');

        islandTraversal.Append('B'); // back
    }
}
