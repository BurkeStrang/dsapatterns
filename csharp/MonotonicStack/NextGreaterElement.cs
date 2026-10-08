namespace DsaPatterns.MonotonicStack;

// Given two integer arrays nums1 and nums2, return an array answer such that
// answer[i] is the next greater number for every nums1[i] in nums2.
// The next greater element for an element x is the first element to the right
// of x that is greater than x. If there is no greater number, output -1 for
// that number.
// The numbers in nums1 are all present in nums2.
//
// Examples
//
// Input: nums1 = [4,2,6], nums2 = [6,2,4,5,3,7]
// Output: [5,4,7]
// Explanation: The next greater number for 4 is 5, for 2 is 4, and for 6 is 7
// in nums2.
//
// Input: nums1 = [9,7,1], nums2 = [1,7,9,5,4,3]
// Output: [-1,9,7]
// Explanation: The next greater number for 9 does not exist, for 7 is 9, and
// for 1 is 7 in nums2.
//
// Input: nums1 = [5,12,3], nums2 = [12,3,5,4,10,15]
// Output: [10,15,5]
// Explanation: The next greater number for 5 is 10, for 12 is 15, and for 3 is
// 4 in nums2.
//
// Constraints:
// 1 <= nums1.length <= nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 104
// All integers in nums1 and nums2 are unique.
// All the integers of nums1 also appear in nums2.

internal static class NextGreaterElement
{
    internal static int[] FindNextGreaterElement(int[] nums1, int[] nums2)
    {
        // Create hashmap and stack
        Dictionary<int, int> map = [];
        Stack<int> stack = new();

        // Process each number in nums2
        foreach (int num in nums2)
        {
            // Pop elements from the stack that are smaller than current number
            while (stack.Count > 0 && stack.Peek() < num)
            {
                // Pop element from stack and remember its next greater element
                map[stack.Pop()] = num;
            }

            // Push current number onto stack
            stack.Push(num);
        }

        // Map the remaining numbers on the stack to -1
        for (int i = 0; i < nums1.Length; i++)
        {
            if (map.TryGetValue(nums1[i], out int val))
            {
                nums1[i] = val;
            }
            else
            {
                nums1[i] = -1;
            }
        }

        return nums1;
    }
}
