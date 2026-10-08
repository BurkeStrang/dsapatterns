namespace DsaPatterns.ModifiedBinarySearch;

public class NextLetterTests
{
    public static TheoryData<string, char[], char, char> Cases =>
        new()
        {
            { "key in middle of array", ['a', 'c', 'f', 'h'], 'f', 'h' },
            { "key before first element", ['a', 'c', 'f', 'h'], 'b', 'c' },
            { "key is smallest element", ['a', 'c', 'f', 'h'], 'a', 'c' },
            {
                "key is largest element - wraps around",
                ['a', 'c', 'f', 'h'],
                'h',
                'a'
            },
            {
                "key larger than all - wraps around",
                ['a', 'c', 'f', 'h'],
                'z',
                'a'
            },
            { "key smaller than all elements", ['c', 'f', 'j'], 'a', 'c' },
            {
                "key between two adjacent elements",
                ['a', 'c', 'f', 'h'],
                'g',
                'h'
            },
            { "single element - wraps around", ['m'], 'm', 'm' },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SearchNextLetter(
        string name,
        char[] letters,
        char key,
        char want
    )
    {
        char got = NextLetter.SearchNextLetter(letters, key);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
