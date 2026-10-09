namespace DsaPatterns.TopologicalSort;

public class MinHeightTreesTests
{
    public static TheoryData<int, int[][], int[]> Cases =>
        new()
        {
            {
                4,
                [
                    [1, 0],
                    [1, 2],
                    [1, 3]
                ],
                [1]
            },
            {
                6,
                [
                    [0, 3],
                    [1, 3],
                    [2, 3],
                    [4, 3],
                    [5, 4]
                ],
                [3, 4]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMinHeightTrees(int n, int[][] edges, int[] want)
    {
        List<int> got = MinHeightTrees.FindTrees(n, edges);
        Assert.Equal(want.OrderBy(x => x), got.OrderBy(x => x));
    }
}
