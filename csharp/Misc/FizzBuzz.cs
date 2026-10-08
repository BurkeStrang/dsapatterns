namespace DsaPatterns.Misc;

internal static class FizzBuzz
{
    internal static List<string> Generate(int n)
    {
        List<string> res = new(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (i % 15 == 0)
            {
                res.Add("FizzBuzz");
            }
            else if (i % 5 == 0)
            {
                res.Add("Buzz");
            }
            else if (i % 3 == 0)
            {
                res.Add("Fizz");
            }
            else
            {
                res.Add(i.ToString());
            }
        }

        return res;
    }
}
