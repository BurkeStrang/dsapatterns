namespace DsaPatterns.Backtracking;

public class SudokuSolverTests
{
    // boards are written one string per row, with '.' for an empty cell
    public static TheoryData<string, string[], string[]> Cases =>
        new()
        {
            {
                "Example 1",
                [
                    "53..7....",
                    "6..195...",
                    ".98....6.",
                    "8...6...3",
                    "4..8.3..1",
                    "7...2...6",
                    ".6....28.",
                    "...419..5",
                    "....8..79",
                ],
                [
                    "534678912",
                    "672195348",
                    "198342567",
                    "859761423",
                    "426853791",
                    "713924856",
                    "961537284",
                    "287419635",
                    "345286179",
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void SolveSudoku(string name, string[] board, string[] want)
    {
        char[][] solved = SudokuSolver.SolveSudoku(Shared.ToBoard(board));

        string[] got = solved.Select(row => new string(row)).ToArray();
        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got {Shared.Format(got)}, want {Shared.Format(want)}"
        );
    }
}
