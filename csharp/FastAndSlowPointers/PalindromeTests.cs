namespace DsaPatterns.FastAndSlowPointers;

public class PalindromeTests
{
    public static TheoryData<int[], bool> Cases =>
        new()
        {
            { [2, 4, 6, 4, 2], true },
            { [2, 4, 6, 4, 2, 2], false },
            { [], true },
            { [1], true },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void IsPalindrome(int[] input, bool expected)
    {
        bool got = Palindrome.IsPalindrome(Shared.ToList(input));

        Assert.Equal(expected, got);
    }
}
