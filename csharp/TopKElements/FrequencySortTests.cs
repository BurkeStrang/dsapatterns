namespace DsaPatterns.TopKElements;

public class FrequencySortTests
{
    // want is one valid answer; characters with the same frequency can come
    // back in any order
    public static TheoryData<string, string, string> Cases =>
        new()
        {
            { "Example 1", "Programming", "rrmmggainPo" },
            { "Example 2", "abcbab", "bbbaac" },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SortCharacterByFrequency(string name, string s, string want)
    {
        string got = FrequencySort.SortCharacterByFrequency(s);

        Assert.True(
            ValidFrequencySort(s, got),
            $"{name}: got \"{got}\", want something like \"{want}\""
        );
    }

    private static bool ValidFrequencySort(string input, string output)
    {
        if (input.Length != output.Length)
        {
            return false;
        }

        Dictionary<char, int> freq = [];
        foreach (char c in input)
        {
            freq[c] = freq.GetValueOrDefault(c) + 1;
        }

        int prevFreq = int.MaxValue;
        int i = 0;
        while (i < output.Length)
        {
            char c = output[i];
            int count = 0;
            while (i < output.Length && output[i] == c)
            {
                count++;
                i++;
            }

            if (freq.GetValueOrDefault(c) != count || count > prevFreq)
            {
                return false;
            }

            prevFreq = count;
        }

        return true;
    }
}
