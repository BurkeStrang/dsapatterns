namespace DsaPatterns.KnapsackDp;

// You are given a set of positive numbers and a target sum ‘S’.
// Each number should be assigned either a ‘+’ or ‘-’ sign.
// We need to find the total ways to assign symbols to make the sum of the
// numbers equal to the target ‘S’.
//
// Example 1:
// Input: {1, 1, 2, 3}, S=1
// Output: 3
// Explanation: The given set has '3' ways to make a sum of '1': {+1-1-2+3} &
// {-1+1-2+3} & {+1+1+2-3}
//
// Example 2:
// Input: {1, 2, 7, 1}, S=9
// Output: 2
// Explanation: The given set has '2' ways to make a sum of '9': {+1+2+7-1} &
// {-1+2+7+1}

internal static class TargetSum
{
    internal static int FindTargetSubsets(int[] num, int target)
    {
        int totalSum = 0;
        foreach (int n in num)
        {
            totalSum += n;
        }

        if (totalSum < target || (target + totalSum) % 2 == 1)
        {
            return 0;
        }

        return CountSets(num, (target + totalSum) / 2);
    }

    private static int CountSets(int[] num, int sum)
    {
        int n = num.Length;
        int[,] dp = new int[n, sum + 1];

        for (int i = 0; i < n; i++)
        {
            dp[i, 0] = 1;
        }

        for (int s = 1; s <= sum; s++)
        {
            if (num[0] == s)
            {
                dp[0, s] = 1;
            }
            else
            {
                dp[0, s] = 0;
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int s = 1; s <= sum; s++)
            {
                dp[i, s] = dp[i - 1, s];
                if (s >= num[i])
                {
                    dp[i, s] += dp[i - 1, s - num[i]];
                }
            }
        }

        return dp[n - 1, sum];
    }
}
