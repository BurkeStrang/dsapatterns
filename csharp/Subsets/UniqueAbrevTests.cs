namespace DsaPatterns.Subsets;

public class UniqueAbrevTests
{
    public static TheoryData<string, string, string[]> Cases =>
        new()
        {
            {
                "word",
                "word",
                [
                    "word",
                    "1ord",
                    "w1rd",
                    "wo1d",
                    "wor1",
                    "2rd",
                    "w2d",
                    "wo2",
                    "1o1d",
                    "1or1",
                    "w1r1",
                    "1o2",
                    "2r1",
                    "3d",
                    "w3",
                    "4",
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void GenerateGeneralizedAbbreviation(
        string name,
        string word,
        string[] want
    )
    {
        List<string> got = UniqueAbrev.GenerateGeneralizedAbbreviation(word);

        // the abbreviations can come back in any order
        Assert.True(
            got.Order().SequenceEqual(want.Order()),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
