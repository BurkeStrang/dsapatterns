namespace DsaPatterns.TopKElements;

public class RearrangeStringTests
{
    // possible says whether the letters can be rearranged so that no two
    // neighbours are the same; when they can't, an empty string is expected
    public static TheoryData<string, string, bool> Cases =>
        new()
        {
            { "two letters", "aappp", true },
            { "many letters", "Programming", true },
            { "not possible", "aapa", false },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Rearrange(string name, string str, bool possible)
    {
        string got = RearrangeString.Rearrange(str);

        if (!possible)
        {
            Assert.True(got == "", $"{name}: got \"{got}\", want \"\"");
            return;
        }

        bool sameLetters = str.Order().SequenceEqual(got.Order());
        bool noNeighbours = !got.Zip(got.Skip(1)).Any(p => p.First == p.Second);
        Assert.True(sameLetters && noNeighbours, $"{name}: got \"{got}\"");
    }
}
