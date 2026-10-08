namespace DsaPatterns.SlidingWindow;

public class AvgTests
{
    public static TheoryData<string, int, int[], double[]> Cases =>
        new()
        {
            {
                "basic case",
                5,
                [1, 3, 2, 6, -1, 4, 1, 8, 2],
                [2.2, 2.8, 2.4, 3.6, 2.8]
            },
            { "window size 1", 1, [5, 10, 15], [5.0, 10.0, 15.0] },
            { "window size equals array length", 4, [2, 4, 6, 8], [5.0] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindAverages(string name, int k, int[] arr, double[] want)
    {
        double[] got = Avg.FindAverages(k, arr);

        string gotText = string.Join(", ", got);
        string wantText = string.Join(", ", want);
        Assert.True(
            Shared.EqualDoubles(got, want),
            $"{name}: got [{gotText}], want [{wantText}]"
        );
    }
}
