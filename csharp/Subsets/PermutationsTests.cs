namespace DsaPatterns.Subsets;

public class PermutationsTests
{
    public static TheoryData<string, int[], int[][]> Cases =>
        new()
        {
            {
                "3 elements",
                [1, 2, 3],
                [
                    [1, 2, 3],
                    [1, 3, 2],
                    [2, 1, 3],
                    [2, 3, 1],
                    [3, 1, 2],
                    [3, 2, 1],
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindPermutations(string name, int[] nums, int[][] want)
    {
        List<List<int>> got = Permutations.FindPermutations(nums);

        // the order of the numbers within a permutation matters, so only the
        // order of the permutations themselves is ignored
        IEnumerable<string> gotRows = got.Select(Shared.Format).Order();
        IEnumerable<string> wantRows = want.Select(Shared.Format).Order();
        Assert.True(
            gotRows.SequenceEqual(wantRows),
            $"{name}: got {Shared.Format2D(got)}, "
                + $"want {Shared.Format2D(want)}"
        );
    }
}
