namespace DsaPatterns.KnapsackDp;

// Given a set of positive numbers,
// find the total number of subsets whose sum is equal to a given number ‘S’.
//
// Example 1:
// Input: {1, 1, 2, 3}, S=4
// Output: 3
// The given set has '3' subsets whose sum is '4': {1, 1, 2}, {1, 3}, {1, 3}
// Note that we have two similar sets {1, 3}, because we have two '1' in our
// input.
//
// Example 2:
// Input: {1, 2, 7, 1, 5}, S=9
// Output: 3
// The given set has '3' subsets whose sum is '9': {2, 7}, {1, 7, 1}, {1, 2, 1,
// 5}

internal static class CountOfSubsetSum
{
    internal static int CountSubsets(int[] num, int sum)
    {
        return CountSubsetsRecursive(num, sum, 0);
    }

    private static int CountSubsetsRecursive(
        int[] num,
        int sum,
        int currentIndex
    )
    {
        // base checks
        if (sum == 0)
        {
            return 1;
        }

        if (num.Length == 0 || currentIndex >= num.Length)
        {
            return 0;
        }

        // recursive call after selecting the number at the currentIndex
        // if the number at currentIndex exceeds the sum, we shouldn't process
        // this
        int sum1 = 0;
        if (num[currentIndex] <= sum)
        {
            sum1 = CountSubsetsRecursive(
                num,
                sum - num[currentIndex],
                currentIndex + 1
            );
        }

        // recursive call after excluding the number at the currentIndex
        int sum2 = CountSubsetsRecursive(num, sum, currentIndex + 1);

        return sum1 + sum2;
    }
}
