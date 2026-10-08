namespace DsaPatterns.KWayMerge;

// Given two sorted arrays in descending order,
// find ‘K’ pairs with the largest sum where each pair consists of numbers from
// both the arrays.
//
// Example 1:
// Input: nums1=[9, 8, 2], nums2=[6, 3, 1], K=3
// Output: [9, 3], [9, 6], [8, 6]
// Explanation: These 3 pairs have the largest sum. No other pair has a sum
// larger than any of these.
//
// Example 2:
// Input: nums1=[5, 2, 1], nums2=[2, -1], K=3
// Output: [5, 2], [5, -1], [2, 2]

internal static class KPairsLargestSum
{
    // FindKLargestPairs finds k largest pairs.
    internal static List<int[]> FindKLargestPairs(
        int[] nums1,
        int[] nums2,
        int k
    )
    {
        // min-heap of pairs, ordered by their sum
        PriorityQueue<int[], int> minHeap = new();

        for (int i = 0; i < nums1.Length && i < k; i++)
        {
            for (int j = 0; j < nums2.Length && j < k; j++)
            {
                int sum = nums1[i] + nums2[j];
                if (minHeap.Count < k)
                {
                    minHeap.Enqueue([nums1[i], nums2[j]], sum);
                }
                else
                {
                    // if the sum of the two numbers from the two arrays is
                    // smaller than the smallest (top) element of the heap, we
                    // can 'break' here.
                    int[] top = minHeap.Peek();
                    if (sum < top[0] + top[1])
                    {
                        break;
                    }

                    // we've a pair with a larger sum, remove top and insert
                    // this pair in heap
                    minHeap.Dequeue();
                    minHeap.Enqueue([nums1[i], nums2[j]], sum);
                }
            }
        }

        List<int[]> result = new(minHeap.Count);
        while (minHeap.Count > 0)
        {
            result.Add(minHeap.Dequeue());
        }

        return result;
    }
}
