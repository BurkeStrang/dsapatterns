namespace DsaPatterns.PrefixSum;

// Given an array of integers nums and an integer k,
// find the length of the longest subarray that sums to k.
// If no such subarray exists, return 0.
//
// Example 1:
// Input: nums = [1, 2, 3, -2, 5], k = 5
// Output: 2
// Explanation: The longest subarray with a sum of 5 is [2, 3], which has a length of 2.
//
// Example 2:
// Input: nums = [-2, -1, 2, 1], k = 1
// Output: 2
// Explanation: The longest subarray with a sum of 1 is [-1, 2], which has a length of 2.
//
// Example 3:
// Input: nums = [3, 4, 7, 2, -3, 1, 4, 2], k = 7
// Output: 4
// Explanation: The longest subarray with a sum of 7 is [7, 2, -3, 1], which has a length of 4.
//
// Constraints:
// 1 <= nums.length <= 2 * 105
// -104 <= nums[i] <= 104
// -109 <= k <= 109

internal static class MaxSizeSubArraySumEqualsK
{
    internal static int Find(int[] nums, int k)
    {
        // Create a dictionary to store cumulative sums and their earliest indices
        Dictionary<int, int> cumMap = [];
        int cumSum = 0; // Initialize cumulative sum
        int maxLen = 0; // Initialize max length of subarray with sum k

        // Iterate through the array
        for (int i = 0; i < nums.Length; i++)
        {
            cumSum += nums[i]; // Update cumulative sum

            // Check if cumulative sum equals k
            if (cumSum == k)
                maxLen = i + 1; // Update max length

            // Check if there is a subarray with sum k
            if (cumMap.ContainsKey(cumSum - k))
                maxLen = Max(maxLen, i - cumMap[cumSum - k]);

            // Store the cumulative sum and its index
            if (!cumMap.ContainsKey(cumSum))
                cumMap[cumSum] = i;
        }

        return maxLen; // Return the maximum lengt
    }
}
