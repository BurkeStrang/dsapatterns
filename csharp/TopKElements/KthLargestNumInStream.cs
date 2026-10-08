namespace DsaPatterns.TopKElements;

// Design a class to efficiently find the Kth largest element in a stream of
// numbers.
// The class should have the following two things:
// The constructor of the class should accept an integer array containing
// initial numbers from the stream and an integer ‘K’.
// The class should expose a function add(int num) which will store the given
// number and return the Kth largest number.
//
// Example 1:
// Input: [3, 1, 5, 12, 2, 11], K = 4
// 1. Calling add(6) should return '5'.
// 2. Calling add(13) should return '6'.
// 2. Calling add(4) should still return '6'.

internal class KthLargestNumInStream
{
    // min heap to store the k largest elements seen so far
    private readonly PriorityQueue<int, int> minHeap = new();

    // The value of 'k'
    private readonly int k;

    internal KthLargestNumInStream(int[] nums, int k)
    {
        this.k = k;
        foreach (int num in nums)
        {
            Add(num);
        }
    }

    internal int Add(int num)
    {
        minHeap.Enqueue(num, num);
        if (minHeap.Count > k)
        {
            minHeap.Dequeue();
        }

        return minHeap.Peek();
    }
}
