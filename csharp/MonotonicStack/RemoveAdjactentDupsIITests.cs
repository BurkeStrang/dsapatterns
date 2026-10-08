namespace DsaPatterns.MonotonicStack;

public class RemoveAdjactentDupsIITests
{
    public static TheoryData<string, string, int, string> Cases =>
        new()
        {
            { "remove bbb then aaa", "abbbaaca", 3, "ca" },
            { "no removal possible", "abbaccaa", 3, "abbaccaa" },
            { "remove ccc then aaa", "abbacccaa", 3, "abb" },
            { "all removed", "aaa", 3, "" },
            { "single char, k=2", "a", 2, "a" },
            { "multiple removals", "deeedbbcccbdaa", 3, "aa" },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void RemoveDuplicatesII(string name, string s, int k, string want)
    {
        string got = RemoveAdjactentDupsII.RemoveDuplicatesII(s, k);

        Assert.True(got == want, $"{name}: got \"{got}\", want \"{want}\"");
    }
}
