namespace DsaPatterns.Backtracking;

// Numbers can be regarded as the product of their factors.
// For example, 8 = 2 x 2 x 2 = 2 x 4.
// Given an integer n,
// return all possible combinations of its factors.
// You may return the answer in any order.
//
// Example 1:
// Input: n = 8
// Output: [[2, 2, 2], [2, 4]]
//
// Example 2:
// Input: n = 20
// Output: [[2, 2, 5], [2, 10], [4, 5]]
//
// Constraints:
// 2 <= n <= 107

internal static class FactorCombinations
{
    internal static List<List<int>> GetFactors(int n)
    {
        List<List<int>> result = [];
        GetAllFactors(n, 2, [], result);
        return result;
    }

    private static void GetAllFactors(
        int n,
        int start,
        List<int> curr,
        List<List<int>> result
    )
    {
        for (int i = start; i <= (int)Math.Sqrt(n); i++)
        {
            if (n % i == 0)
            {
                curr.Add(i);
                result.Add([.. curr, n / i]);
                GetAllFactors(n / i, i, curr, result);
                curr.RemoveAt(curr.Count - 1);
            }
        }
    }
}
