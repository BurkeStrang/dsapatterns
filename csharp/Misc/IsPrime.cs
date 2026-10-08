namespace DsaPatterns.Misc;

internal static class IsPrime
{
    internal static bool IsPrimeNumber(int n)
    {
        // no number you can divide n by without leaving a remainder other than
        // 1 and n itself
        if (n < 2)
        {
            return false;
        }

        if (n == 2 || n == 3)
        {
            return true;
        }

        if (n % 2 == 0)
        {
            return false;
        }

        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                return false;
            }
        }

        return true;
    }

    internal static int CountPrimes(int n)
    {
        int count = 0;
        for (int i = 2; i <= n; i++)
        {
            if (IsPrimeNumber(i))
            {
                count++;
            }
        }

        return count;
    }

    internal static List<int> GetPrimes(int n)
    {
        List<int> res = [];
        for (int i = 2; i <= n; i++)
        {
            if (IsPrimeNumber(i))
            {
                res.Add(i);
            }
        }

        return res;
    }
}
