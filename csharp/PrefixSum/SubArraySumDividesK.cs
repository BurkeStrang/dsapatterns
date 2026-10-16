namespace DsaPatterns.PrefixSum;

// Given an array of integers nums and an integer k,
// return the count of non-empty
// subarrays that have a sum that is divisible by k.
// A subarray is a continuous part of an array.
//
// Example 1
// Input: nums = [3, 1, 2, -2, 5, -1], k = 3
// Expected Output: 7
// Justification: The subarrays that sum to a multiple of 3 are:
// [3], [1, 2], [3, 1, 2], [3, 1, 2, -2, 5], [1, 2, -2, 5], [-2, 5], and [2, -2].
//
// Example 2
// Input: nums = [4, 5, 0, -2, -3, 1], k = 5
// Expected Output: 7
// Justification: The subarrays that sum to a multiple of 5 are:
// [5], [4, 5, 0, -2, -3, 1], [5, 0], [0], [5, 0, -2, -3], [0, -2, -3], and [-2, -3].
//
// Example 3
// Input: nums = [-1, 2, 9], k = 2
// Expected Output: 2
// Justification: The subarrays that sum to a multiple of 2 are [2] and [-1, 2, 9].
// Constraints:
//
// 1 <= nums.length <= 3 * 104
// -104 <= nums[i] <= 104
// 2 <= k <= 104


internal static class SubArraySumDividesK
{
    internal static int Count(int[] nums, int k)
    {
        Dictionary<int, int> remainderCount = new()
        {
            [0] = 1
        };
        int cumulativeSum = 0, count = 0;

        foreach (int num in nums)
        {
            cumulativeSum += num;
            int remainder = cumulativeSum % k;
            if (remainder < 0)
                remainder += k;
            if (remainderCount.TryGetValue(remainder, out int freq))
                count += freq;
            else
                remainderCount[remainder] = 0;
            remainderCount[remainder]++;
            // WriteLine($"Num: {num}, Cumulative Sum: {cumulativeSum}, Remainder: {remainder}, Count: {count}");
            // WriteLine($"Remainder Count Map: {string.Join(", ", remainderCount.Select(kv => $"{kv.Key}:{kv.Value}"))}");
        }
        // Return the total count of subarrays
        return count;
    }
}
