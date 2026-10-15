namespace DsaPatterns.OrderedSet;

// Find the length of the longest contiguous subarray within an array of integers,
// where the absolute difference between any two elements
// in this subarray does not exceed a specified limit.
// The challenge lies in ensuring the subarray is continuous and the range
// (difference between the maximum and minimum element in the subarray)
// fits within the given threshold.
//
// Example 1:
// Input: Array = [10, 1, 2, 4, 7], Limit = 5
// Expected Output: 3
// Justification: The longest subarray where the absolute difference
// between any two numbers is at most 5 is [1, 2, 4].
//
// Example 2:
// Input: Array = [4, 8, 5, 1, 7, 9], Limit = 3
// Expected Output: 2
// Justification: One possible longest subarray is [7, 9]
// where the difference between 7 and 9 is within the limit of 3.
//
// Example 3:
// Input: Array = [3, 3, 3, 3, 3], Limit = 0
// Expected Output: 5
// Justification: Since all elements are the same,
// the entire array is the longest subarray with differences of 0.
//
// Constraints:
// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 0 <= limit <= 109

internal static class LongestContinuousSubArray
{
    internal static int Find(int[] nums, int limit)
    {
        SortedDictionary<int, int> map = [];
        int left = 0,
            maxLength = 0;

        for (int right = 0; right < nums.Length; right++)
        {
            if (!map.TryGetValue(nums[right], out _))
                map[nums[right]] = 0;
            map[nums[right]]++;

            // Calculate max and min keys using Linq
            while (map.Keys.Max() - map.Keys.Min() > limit)
            {
                map[nums[left]]--;
                if (map[nums[left]] == 0)
                    map.Remove(nums[left]);
                left++;
            }
            maxLength = Max(maxLength, right - left + 1);
        }
        return maxLength;
    }
}
