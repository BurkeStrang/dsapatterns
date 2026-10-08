namespace DsaPatterns.HashMaps;

public class RansomNoteTests
{
    public static TheoryData<string, string, string, bool> Cases =>
        new()
        {
            {
                "can construct hello from hellworld",
                "hello",
                "hellworld",
                true
            },
            { "can construct notes from stoned", "notes", "stoned", true },
            { "cannot construct apple from pale", "apple", "pale", false },
            { "exact match", "abc", "abc", true },
            { "not enough letters", "aabb", "ab", false },
            { "empty ransom note", "", "anything", true },
            { "empty magazine", "a", "", false },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void CanConstruct(
        string name,
        string ransomNote,
        string magazine,
        bool want
    )
    {
        bool got = RansomNote.CanConstruct(ransomNote, magazine);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
