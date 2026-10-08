namespace DsaPatterns.Backtracking;

// Given an array of distinct positive integers candidates and a target integer
// target,
// return a list of all unique combinations of candidates where the chosen
// numbers sum to target.
// You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times.
// Two combinations are unique if the frequency of at least one of the chosen
// numbers is different.
//
// Example 1:
// Input: candidates = [2, 3, 6, 7], target = 7
// Output: [[2, 2, 3], [7]]
// Explanation: The elements in these two combinations sum up to 7.
//
// Example 2:
// Input: candidates = [2, 4, 6, 8], target = 10
// Output: [[2,2,2,2,2], [2,2,2,4], [2,2,6], [2,4,4], [2,8], [4,6]]
// Explanation: The elements in these six combinations sum up to 10.
// Constraints:
//
// 1 <= candidates.length <= 30
// 2 <= candidates[i] <= 40
// All elements of candidates are distinct.
// 1 <= target <= 40

internal static class CombinationSum
{
    internal static List<List<int>> FindCombinations(
        int[] candidates,
        int target
    )
    {
        List<List<int>> res = [];
        Backtrack(candidates, 0, target, [], res);
        return res;
    }

    private static void Backtrack(
        int[] candidates,
        int start,
        int target,
        List<int> comb,
        List<List<int>> res
    )
    {
        if (target == 0)
        {
            res.Add([.. comb]);
            return;
        }

        for (int i = start; i < candidates.Length; i++)
        {
            if (target < candidates[i])
            {
                continue;
            }

            comb.Add(candidates[i]);
            Backtrack(candidates, i, target - candidates[i], comb, res);
            comb.RemoveAt(comb.Count - 1);
        }
    }
}
