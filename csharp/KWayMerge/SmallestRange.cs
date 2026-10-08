namespace DsaPatterns.KWayMerge;

// Given ‘M’ sorted arrays, find the smallest range that includes at least one
// number from each of the ‘M’ lists.
// Example 1:
// Input: L1=[1, 5, 8], L2=[4, 12], L3=[7, 8, 10]
// Output: [4, 7]
// Explanation: The range [4, 7] includes 5 from L1, 4 from L2 and 7 from L3.
//
// Example 2:
// Input: L1=[1, 9], L2=[4, 12], L3=[7, 10, 16]
// Output: [9, 12]
// Explanation: The range [9, 12] includes 9 from L1, 12 from L2 and 10 from L3

internal record struct NodeElement(int ElementIndex, int ArrayIndex);

internal static class SmallestRange
{
    internal static int[] FindSmallestRange(int[][] lists)
    {
        // min-heap of positions, ordered by the number at that position
        PriorityQueue<NodeElement, int> minHeap = new();

        int rangeStart = 0;
        int rangeEnd = int.MaxValue;
        int currentMaxNumber = int.MinValue;

        for (int i = 0; i < lists.Length; i++)
        {
            if (lists[i].Length > 0)
            {
                minHeap.Enqueue(new NodeElement(0, i), lists[i][0]);
                if (lists[i][0] > currentMaxNumber)
                {
                    currentMaxNumber = lists[i][0];
                }
            }
        }

        while (minHeap.Count == lists.Length)
        {
            NodeElement node = minHeap.Dequeue();
            int current = lists[node.ArrayIndex][node.ElementIndex];
            if (rangeEnd - rangeStart > currentMaxNumber - current)
            {
                rangeStart = current;
                rangeEnd = currentMaxNumber;
            }

            node.ElementIndex++;
            if (lists[node.ArrayIndex].Length > node.ElementIndex)
            {
                int next = lists[node.ArrayIndex][node.ElementIndex];
                minHeap.Enqueue(node, next);
                if (next > currentMaxNumber)
                {
                    currentMaxNumber = next;
                }
            }
        }

        return [rangeStart, rangeEnd];
    }
}
