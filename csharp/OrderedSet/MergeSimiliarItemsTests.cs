namespace DsaPatterns.OrderedSet;

public class MergeSimiliarItemsTests
{
    public static TheoryData<string, int[][], int[][], int[][]> Cases =>
        new()
        {
            { "Example 1", [[1,2],[4,3]], [[2,1],[4,3],[3,4]], [[1,2],[2,1],[3,4],[4,6]]},
            { "Example 2", [[5,5]], [[5,10]], [[5,15]]},
            { "Example 3", [[1,1],[2,2]], [[3,3]], [[1,1],[2,2],[3,3]] }
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Merge(string name, int[][] items1, int[][] items2, int[][] want)
    {
        var got = MergeSimilarItems.Merge(items1, items2);

        Assert.True(got.Count == want.Length &&
                got.All(g => want.Any(w => w[0] == g[0] && w[1] == g[1]))
                , $"{name}: got {string.Join(", ", got.Select(g => $"[{g[0]}, {g[1]}]"))}, want {string.Join(", ", want.Select(w => $"[{w[0]}, {w[1]}]"))}");
    }
}
