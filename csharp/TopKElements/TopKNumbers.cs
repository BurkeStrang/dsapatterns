namespace DsaPatterns.TopKElements;

// Given an unsorted array of numbers, find the ‘K’ largest numbers in it.
//
// Example 1:
// Input: [3, 1, 5, 12, 2, 11], K = 3
// Output: [5, 12, 11]
//
// Example 2:
// Input: [5, 12, 11, -1, 12], K = 3
// Output: [12, 11, 12]

// findKLargestNumbers - keeps all comments same and method name same

internal static class TopKNumbers
{
    internal static int[] FindKLargestNumbers(int[] nums, int k)
    {
        PriorityQueue<int, int> minHeap = new();

        // put first 'K' numbers in the min heap
        for (int i = 0; i < k; i++)
        {
            minHeap.Enqueue(nums[i], nums[i]);
        }

        // go through the remaining numbers of the array, if the number from
        // the array is bigger than the top (smallest) number of the min-heap,
        // remove the top number from heap and add the number from array
        for (int i = k; i < nums.Length; i++)
        {
            if (nums[i] > minHeap.Peek())
            {
                minHeap.Dequeue();
                minHeap.Enqueue(nums[i], nums[i]);
            }
        }

        // the heap has the top 'K' numbers, return them in an array
        int[] result = new int[minHeap.Count];
        for (int i = 0; i < result.Length; i++)
        {
            result[i] = minHeap.Dequeue();
        }

        return result;
    }
}
