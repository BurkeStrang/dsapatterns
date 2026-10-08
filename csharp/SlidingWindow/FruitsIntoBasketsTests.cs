namespace DsaPatterns.SlidingWindow;

public class FruitsIntoBasketsTests
{
    public static TheoryData<string, char[], int> Cases =>
        new()
        {
            { "basic example", ['A', 'B', 'C', 'A', 'C'], 3 },
            { "all same fruit", ['A', 'A', 'A', 'A'], 4 },
            { "two types alternating", ['A', 'B', 'A', 'B', 'A', 'B'], 6 },
            { "three types", ['A', 'B', 'C', 'B', 'B', 'C', 'A'], 5 },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void MaxFruit(string name, char[] arr, int want)
    {
        int got = FruitsIntoBaskets.MaxFruit(arr);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
