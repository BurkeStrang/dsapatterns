namespace DsaPatterns.Misc;

public class FizzBuzzTests
{
    public static TheoryData<string, int, string[]> Cases =>
        new()
        {
            { "5", 5, ["1", "2", "Fizz", "4", "Buzz"] },
            {
                "15",
                15,
                [
                    "1",
                    "2",
                    "Fizz",
                    "4",
                    "Buzz",
                    "Fizz",
                    "7",
                    "8",
                    "Fizz",
                    "Buzz",
                    "11",
                    "Fizz",
                    "13",
                    "14",
                    "FizzBuzz",
                ]
            },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void Generate(string name, int n, string[] want)
    {
        List<string> got = FizzBuzz.Generate(n);

        Assert.True(
            got.SequenceEqual(want),
            $"{name}: got [{string.Join(", ", got)}], "
                + $"want [{string.Join(", ", want)}]"
        );
    }
}
