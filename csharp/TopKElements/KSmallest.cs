namespace DsaPatterns.TopKElements;

// Given an unsorted array of numbers, find Kth smallest number in it.
// Please note that it is the Kth smallest number in the sorted order,
// not the Kth distinct element.
// Note: For a detailed discussion about different approaches to solve this
// problem,
// take a look at Kth Smallest Number.
//
// Example 1:
// Input: [1, 5, 12, 2, 11, 5], K = 3
// Output: 5
// Explanation: The 3rd smallest number is '5', as the first two smaller numbers
// are [1, 2].
//
// Example 2:
// Input: [1, 5, 12, 2, 11, 5], K = 4
// Output: 5
// Explanation: The 4th smallest number is '5', as the first three small numbers
// are [1, 2, 5].
//
// Example 3:
// Input: [5, 12, 11, -1, 12], K = 3
// Output: 11
// Explanation: The 3rd smallest number is '11', as the first two small numbers
// are [5, -1].

internal static class KSmallest
{
    internal static int FindKthSmallestNumber(int[] nums, int k)
    {
        PriorityQueue<int, int> maxHeap = Shared.NewMaxHeap<int>();

        for (int i = 0; i < k; i++)
        {
            maxHeap.Enqueue(nums[i], nums[i]);
        }

        for (int i = k; i < nums.Length; i++)
        {
            if (nums[i] < maxHeap.Peek())
            {
                maxHeap.Dequeue();
                maxHeap.Enqueue(nums[i], nums[i]);
            }
        }

        return maxHeap.Peek();
    }
}
