namespace DsaPatterns.CyclicalSort;

// Given an unsorted array containing numbers and a number ‘k’,
// find the first ‘k’ missing positive numbers in the array.
//
// Example 1:
// Input: [3, -1, 4, 5, 5], k=3
// Output: [1, 2, 6]
// Explanation: The smallest missing positive numbers are 1, 2 and 6.
//
// Example 2:
// Input: [2, 3, 4], k=3
// Output: [1, 5, 6]
// Explanation: The smallest missing positive numbers are 1, 5 and 6.
//
// Example 3:
// Input: [-2, -3, 4], k=2
// Output: [1, 2]
// Explanation: The smallest missing positive numbers are 1 and 2.
// Constraints:
//
// 1 <= nums.length <= 1000
// 1 <= nums[i] <= 1000
// 1 <= k <= 1000

internal static class FindFirstKNums
{
    internal static List<int> FindFirstK(int[] nums, int k)
    {
        int i = 0;
        // Phase 1: Rearrange elements to their correct positions
        while (i < nums.Length)
        {
            if (
                nums[i] > 0
                && nums[i] <= nums.Length
                && nums[i] != nums[nums[i] - 1]
            )
            {
                // Swap elements to their correct positions
                Shared.Swap(nums, i, nums[i] - 1);
            }
            else
            {
                i++;
            }
        }

        List<int> missingNumbers = [];
        HashSet<int> extraNumbers = [];

        // Phase 2: Identify missing and extra numbers
        for (i = 0; i < nums.Length && missingNumbers.Count < k; i++)
        {
            if (nums[i] != i + 1)
            {
                missingNumbers.Add(i + 1); // Track missing numbers
                extraNumbers.Add(nums[i]); // Track extra numbers
            }
        }

        // Phase 3: Find remaining missing numbers
        for (i = 1; missingNumbers.Count < k; i++)
        {
            int candidateNumber = i + nums.Length;
            // Ignore if the array contains the candidate number
            if (!extraNumbers.Contains(candidateNumber))
            {
                // Add remaining missing numbers
                missingNumbers.Add(candidateNumber);
            }
        }

        return missingNumbers;
    }
}
