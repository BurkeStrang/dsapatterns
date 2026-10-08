namespace DsaPatterns.FastAndSlowPointers;

public class HappyNumTests
{
    public static TheoryData<string, int, bool> Cases =>
        new()
        {
            { "Happy number 19", 19, true },
            { "Happy number 1", 1, true },
            { "Unhappy number 2", 2, false },
            { "Unhappy number 4", 4, false },
        };

    [Theory]
    [MemberData(nameof(Cases))]
    public void IsHappy(string name, int num, bool want)
    {
        bool got = HappyNum.IsHappy(num);

        Assert.True(got == want, $"{name}: got {got}, want {want}");
    }
}
