namespace DsaPatterns.CyclicalSort;

// We are given an unsorted array containing n numbers taken from the range 1 to
// n.
// The array has some numbers appearing twice,
// find all these duplicate numbers using constant space.
//
// Example 1:
// Input: [3, 4, 4, 5, 5]
// Output: [4, 5]
//
// Example 2:
// Input: [5, 4, 7, 2, 3, 5, 3]
// Output: [3, 5]
// Constraints:
//
// nums.length == n
// 1 <= n <=
// 1 <= nums[i] <= n
// Each element in nums appears once or twice.

internal static class FindDups
{
    internal static List<int> FindDuplicates(int[] nums)
    {
        int i = 0;
        while (i < nums.Length)
        {
            int j = nums[i] - 1;
            // Check if the current element is not in its correct position.
            if (nums[i] != nums[j])
            {
                // Swap the current element with the element at its correct
                // position.
                Shared.Swap(nums, i, j);
            }
            else
            {
                // Move to the next element if the current element is already
                // in its correct position.
                i++;
            }
        }

        List<int> duplicateNumbers = [];
        for (i = 0; i < nums.Length; i++)
        {
            // Identify elements that are not in their correct positions, which
            // are duplicates.
            if (nums[i] != i + 1)
            {
                // Add the duplicates to the list.
                duplicateNumbers.Add(nums[i]);
            }
        }

        return duplicateNumbers;
    }
}
