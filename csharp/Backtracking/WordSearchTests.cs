namespace DsaPatterns.Backtracking;

public class WordSearchTests
{
    // boards are written one string per row
    public static TheoryData<string, string[], string, bool> Cases =>
        new()
        {
            { "test1", ["ABCE", "SFCS", "ADEE"], "ABCCED", true },
            { "test2", ["ABCE", "SFCS", "ADEE"], "SEE", true },
            { "test3", ["ABCE", "SFCS", "ADEE"], "XYZ", false },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Exist(string name, string[] board, string word, bool want)
    {
        bool got = WordSearch.Exist(Shared.ToBoard(board), word);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
