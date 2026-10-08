namespace DsaPatterns.TwoPointers;

public class ComparingStringsBackslashTests
{
    public static TheoryData<string, string, string, bool> Cases =>
        new()
        {
            { "Example 1", "xy#z", "xzz#", true },
            { "Example 2", "xy#z", "xyz#", false },
            { "Example 3", "xp#", "xyz##", true },
            { "Example 4", "xywrrmp", "xywrrmu#p", true },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Compare(string name, string str1, string str2, bool want)
    {
        bool got = ComparingStringsBackslash.Compare(str1, str2);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
