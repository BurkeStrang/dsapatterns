namespace DsaPatterns.TwoHeaps;

public class MedianNumberStreamTests
{
    // each case is the numbers to insert and the expected median after each
    // insert
    public static TheoryData<string, int[], double[]> Cases =>
        new()
        {
            { "ordered", [1, 2, 3, 4, 5], [1.0, 1.5, 2.0, 2.5, 3.0] },
            { "unordered", [5, 3, 8, 1, 2], [5, 4, 5, 4, 3] },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void FindMedian(string name, int[] nums, double[] expected)
    {
        MedianNumberStream stream = new();

        for (int i = 0; i < nums.Length; i++)
        {
            stream.InsertNum(nums[i]);
            double median = stream.FindMedian();

            Assert.True(
                median == expected[i],
                $"{name}: after inserting {nums[i]}, "
                    + $"expected median {expected[i]}, got {median}"
            );
        }
    }
}
