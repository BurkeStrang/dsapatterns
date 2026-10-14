namespace DsaPatterns.OrderedSet;

// Given an array nums, containing N integers.
// A 132 pattern is three numbers taken from nums in order of position:
// indices i < j < k with nums[i] < nums[k] < nums[j].
// Naming them x, y and z, that is x < z and z < y, with x appearing first,
// then y, then z.
// It is called a '132' pattern because if you write the three as 1, 3 and 2 by size,
// the order they appear in is 1, then 3, then 2.
// The positions matter as much as the values.
// [3, 1, 4, 2] has a 132 pattern, taking 1, then 4, then 2.
// [4, 3, 2, 1] does not, even though it contains three numbers with those relative sizes,
// because no arrangement of them appears in that order.
// Return true if such a pattern exists within any sequence of given numbers nums. Otherwise, return false.
//
// Example 1:
// Input: nums = [3, 5, 0, 3, 4]
// Expected Output: True
// Justification: Here, 3 < 4 and 4 < 5, forming a '132' pattern with the numbers 3, 5, and 4.
//
// Example 2:
// Input: nums = [1, 2, 3, 4]
// Expected Output: False
// Justification: The sequence is in ascending order, and no '132' pattern is present.
//
// Example 3:
// Input: nums = [9, 11, 8, 9, 10, 7, 9]
// Expected Output: True
// Justification: The pattern is formed with 8 < 9 and 9 < 10 in sequence 8, 10, 9.
//
// Constraints:
// n == nums.length
// 1 <= n <= 2 * 105
// -109 <= nums[i] <= 109


internal static class Pattern132
{
    internal static bool Find(int[] nums)
    {
        SortedSet<int> second = []; // SortedSet to store potential candidates for the second number
        Stack<int> st = new(); // Stack to manage the numbers

        int size = nums.Length;

        // Iterate through the array from the end to the beginning
        for (int i = size - 1; i >= 0; i--)
        {
            // Pop elements from the stack that are smaller than the current number
            while (st.Count > 0 && st.Peek() < nums[i])
            {
                second.Add(st.Pop());
            }

            // Check if the current number can be part of a 132 pattern
            if (st.Count > 0 && second.Count > 0)
            {
                // Find the smallest number in the set greater than nums[i]
                foreach (int val in second)
                {
                    if (val > nums[i])
                    {
                        return true; // If such a number exists, we found a 132 pattern
                    }
                }
            }

            // Push the current number onto the stack
            st.Push(nums[i]);
        }

        // No 132 pattern found
        return false;
    }
}
