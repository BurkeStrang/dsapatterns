namespace DsaPatterns.CyclicalSort;

// We are given an array containing n distinct numbers taken from the range 0 to
// n.
// Since the array has only n numbers out of the total n+1 numbers, find the
// missing number.
//
// Example 1:
// Input: [4, 0, 3, 1]
// Output: 2
//
// Example 2:
// Input: [8, 3, 5, 2, 4, 6, 0, 1]
// Output: 7
//
// Constraints:
// n == nums.length
// 1 <= n <=
// 0 <= nums[i] <= n
// All the numbers of nums are unique.

internal static class FindMissingNum
{
    internal static int FindMissingNumber(int[] nums)
    {
        int i = 0;
        while (i < nums.Length)
        {
            if (nums[i] < nums.Length && nums[i] != nums[nums[i]])
            {
                Shared.Swap(nums, i, nums[i]);
            }
            else
            {
                i++;
            }
        }

        // Find the first number missing from its index, that will be our
        // required number
        for (i = 0; i < nums.Length; i++)
        {
            if (nums[i] != i)
            {
                return i;
            }
        }

        return nums.Length;
    }
}
