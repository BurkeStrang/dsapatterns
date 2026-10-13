namespace DsaPatterns.UnionFind;

// You are given a 2D array heights[][] of size n x m,
// where heights[n][m] represents the height of the cell (n, m).
// Find a path from the top-left corner to the bottom-right c
// orner that minimizes the effort required to travel between consecutive points,
// where effort is defined as the absolute difference in height between two points.
// In a single step, you can either move up, down, left or right.
// Return the minimum effort required for any path from the first point to the last.
//
// Example 1:
// Input: heights =
//  [[1,2,3],[3,8,4],[5,3,5]]
// Expected Output: 1
// Justification: The path with the minimum effort is along the edges of the grid (right, right, down, down)
// which requires an effort of 1 between each pair of points.
//
// Example 2:
// Input: heights =
// [[1,2,2],[3,3,3],[5,3,1]]
// Expected Output: 2
// Justification: The path that minimizes the maximum effort goes through (1,2,2,3,1),
// which has a maximum effort of 2 (from 3 to 1).
//
// Example 3:
// Input: heights =
// [[1,1,1],[1,1,1],[1,1,1]]
// Expected Output: 0
// Justification: The path that minimizes the maximum effort goes through (1,1,1,1,1),
// which has a maximum effort of 0.
//
// Constraints:
// rows == heights.length
// columns == heights[i].length
// 1 <= rows, columns <= 100
// 1 <= heights[i][j] <= 106


internal class Edge(int x, int y, int difference)
{
    public int X = x;
    public int Y = y;
    public int Difference = difference;
}

internal static class PathMinEffot
{
    internal static int MinimumEffortPath(int[][] heights)
    {
        int row = heights.Length;
        int col = heights[0].Length;

        int[] parent = new int[row * col];
        int[] rank = new int[row * col];

        UnionFind uf = new(row * col);

        List<Edge> edges = [];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i > 0)
                {
                    edges.Add(new Edge(
                        i * col + j,
                        (i - 1) * col + j,
                        Math.Abs(heights[i][j] - heights[i - 1][j])
                    ));
                }

                if (j > 0)
                {
                    edges.Add(new Edge(
                        i * col + j,
                        i * col + j - 1,
                        Math.Abs(heights[i][j] - heights[i][j - 1])
                    ));
                }
            }
        }

        edges.Sort((a, b) =>
            a.Difference.CompareTo(b.Difference));

        foreach (var edge in edges)
        {
            uf.Union(edge.X, edge.Y);

            if (uf.Connected(0, row * col - 1))
            {
                return edge.Difference;
            }

        }

        return 0;
    }
}
