namespace DsaPatterns.TopKElements;

public class RearrangeDistTests
{
    // want is one valid answer; letters with the same frequency can be
    // picked in any order
    public static TheoryData<string, string, int, string> Cases =>
        new() { { "Example 1", "mmpp", 2, "mpmp" } };

    [Theory]
    [MemberData(nameof(Cases))]
    public void ReorganizeString(string name, string str, int k, string want)
    {
        string got = RearrangeDist.ReorganizeString(str, k);

        Assert.True(
            ValidRearrangement(str, got, k),
            $"{name}: got \"{got}\", want something like \"{want}\""
        );
    }

    // Reports whether output uses exactly the letters of input, with every
    // repeat of a letter at least k positions after the previous one.
    private static bool ValidRearrangement(string input, string output, int k)
    {
        if (!input.Order().SequenceEqual(output.Order()))
        {
            return false;
        }

        Dictionary<char, int> lastSeen = [];
        for (int i = 0; i < output.Length; i++)
        {
            if (
                lastSeen.TryGetValue(output[i], out int previous)
                && i - previous < k
            )
            {
                return false;
            }

            lastSeen[output[i]] = i;
        }

        return true;
    }
}
