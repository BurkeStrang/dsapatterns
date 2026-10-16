namespace DsaPatterns.PrefixSum;

// Given a binary called nums and an integer called goal,
// return the number of subarrays that have a sum equal to goal.
// A subarray is a part of the array that is continuous,
// meaning all its elements are next to each other.
//
// Example 1
// Input: nums = [1, 1, 0, 1, 1], goal = 2
// Expected Output: 5
// Justification: The subarrays with a sum of 2 are:
// [1, 1] (from index 0 to 1),
// [1, 1, 0] (from index 0 to 2),
// [1, 0, 1] (from index 1 to 3),
// [0, 1, 1] (from index 2 to 4), and
// [1, 1] (from index 3 to 4).
//
// Example 2
// Input: nums = [1, 1, 1, 1, 0, 0], goal = 3
// Expected Output: 4
// Justification: The subarrays with a sum of 3 are:
// [1, 1, 1] (from index 0 to 2),
// [1, 1, 1] (from index 1 to 3),
// [1, 1, 1, 0] (from index 1 to 4), and
// [1, 1, 1, 0, 0] (from index 1 to 5).
//
// Example 3
// Input: nums = [0, 0, 0, 0, 1, 0, 1], goal = 1
// Expected Output: 12
// Justification: The subarrays with a sum of 1 are:
// [0, 0, 0, 0, 1],
// [0, 0, 0, 1],
// [0, 0, 1],
// [0, 1],
// [1],
// [0, 0, 0, 0, 1, 0],
// [0, 0, 0, 1, 0],
// [0, 0, 1, 0],
// [0, 1, 0],
// [1, 0],
// [0, 1],
// and [1].
//
// Constraints:
// 1 <= nums.length <= 3 * 104
// nums[i] is either 0 or 1.
// 0 <= goal <= nums.length


internal static class BinarySubArraySum
{
    internal static int Find(int[] nums, int goal)
    {
        // WriteLine($"Input Array: {string.Join(", ", nums)}, Target Sum: {goal}");
        // WriteLine("--------------------------------------------------");
        int count = 0; // Initialize count of subarrays
        int prefix_sum = 0; // Initialize prefix sum
        Dictionary<int, int> prefix_sums = [];
        prefix_sums.Add(0, 1);

        foreach (int num in nums)
        {
            prefix_sum += num; // Update prefix sum
            // If (prefix_sum - goal) exists in hashmap,
            // it means we found a subarray with sum equals to goal
            if (prefix_sums.ContainsKey(prefix_sum - goal))
                count += prefix_sums[prefix_sum - goal];
            // Update the hashmap with current prefix sum
            if (!prefix_sums.TryAdd(prefix_sum, 1))
                prefix_sums[prefix_sum]++;
            // WriteLine($"Current Number: {num}, Prefix Sum: {prefix_sum}, Count: {count}");
            // WriteLine($"Prefix Sums Map: {string.Join(", ", prefix_sums.Select(kv => $"{kv.Key}:{kv.Value}"))}");
        }

        return count; // Return the count of subarrays
    }
}
