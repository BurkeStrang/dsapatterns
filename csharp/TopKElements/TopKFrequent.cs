namespace DsaPatterns.TopKElements;

// Given an unsorted array of numbers,
// find the top ‘K’ frequently occurring numbers in it.
//
// Example 1:
// Input: [1, 3, 5, 12, 11, 12, 11], K = 2
// Output: [12, 11]
// Explanation: Both '11' and '12' appeared twice.
//
// Example 2:
// Input: [5, 12, 11, 3, 11], K = 2
// Output: [11, 5] or [11, 12] or [11, 3]
// Explanation: Only '11' appeared twice; all other numbers appeared once.

internal static class TopKFrequent
{
    internal static int[] FindTopKFrequentNumbers(int[] nums, int k)
    {
        // Find the frequency of each number
        Dictionary<int, int> numFrequencyMap = [];
        foreach (int n in nums)
        {
            numFrequencyMap[n] = numFrequencyMap.GetValueOrDefault(n) + 1;
        }

        // Create a min heap to store numbers ordered by frequency
        PriorityQueue<int, int> minFreqHeap = new();

        // Go through all numbers in numFrequencyMap and push them into the
        // minHeap. If the heap size is more than k, remove the smallest (top)
        // entry
        foreach ((int num, int frequency) in numFrequencyMap)
        {
            minFreqHeap.Enqueue(num, frequency);
            if (minFreqHeap.Count > k)
            {
                minFreqHeap.Dequeue();
            }
        }

        // Create a list of top k frequent numbers
        int[] topNumbers = new int[k];
        for (int i = k - 1; i >= 0; i--)
        {
            topNumbers[i] = minFreqHeap.Dequeue();
        }

        return topNumbers;
    }
}
