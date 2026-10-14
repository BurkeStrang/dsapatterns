namespace DsaPatterns.OrderedSet;

public class Pattern123Tests
{
    public static TheoryData<string, int[], bool> Cases =>
        new()
        {
            { "Example 1", [3, 5, 0, 3, 4], true },
            { "Example 2", [1, 2, 3, 4], false },
            { "Example 3", [9, 11, 8, 9, 10, 7, 9], true },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Find132Pattern(string name, int[] nums, bool want)
    {
        bool got = Pattern132.Find(nums);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
