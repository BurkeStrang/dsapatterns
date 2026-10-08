namespace DsaPatterns.KWayMerge;

// Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.
//
// Example 1:
// Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
// Output: 4
// Explanation: The 5th smallest number among all the arrays is 4, this can be
// verified from
// the merged list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]
//
// Example 2:
// Input: L1=[5, 8, 9], L2=[1, 7], K=3
// Output: 7
// Explanation: The 3rd smallest number among all the arrays is 7.

internal record struct Node(int ElementIndex, int ArrayIndex);

internal static class KSmallest
{
    internal static int FindKthSmallest(int[][] lists, int k)
    {
        // min-heap of positions, ordered by the number at that position
        PriorityQueue<Node, int> minHeap = new();

        // put the 1st element of each array in the min heap
        for (int i = 0; i < lists.Length; i++)
        {
            if (lists[i].Length > 0)
            {
                minHeap.Enqueue(new Node(0, i), lists[i][0]);
            }
        }

        // take the smallest (top) element form the min heap, if the running
        // count is equal to k return the number if the array of the top
        // element has more elements, add the next element to the heap
        int numberCount = 0;
        int result = 0;
        while (minHeap.Count > 0)
        {
            Node node = minHeap.Dequeue();
            result = lists[node.ArrayIndex][node.ElementIndex];
            numberCount++;
            if (numberCount == k)
            {
                break;
            }

            node.ElementIndex++;
            if (lists[node.ArrayIndex].Length > node.ElementIndex)
            {
                minHeap.Enqueue(
                    node,
                    lists[node.ArrayIndex][node.ElementIndex]
                );
            }
        }

        return result;
    }
}
