namespace DsaPatterns.KWayMerge;

// Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.
// Example 1:
// Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
// Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]
//
// Example 2:
// Input: L1=[5, 8, 9], L2=[1, 7]
// Output: [1, 5, 7, 8, 9]

internal class ListNode(int val, ListNode? next = null)
{
    public int Val { get; set; } = val;
    public ListNode? Next { get; set; } = next;
}

internal static class MergeKSortedList
{
    // Merge merges the given lists into one sorted list.
    internal static ListNode? Merge(ListNode?[] lists)
    {
        // min-heap of nodes, ordered by their value
        PriorityQueue<ListNode, int> minHeap = new();

        // put the root of each list in the min heap
        foreach (ListNode? root in lists)
        {
            if (root != null)
            {
                minHeap.Enqueue(root, root.Val);
            }
        }

        // take the smallest (top) element form the min-heap and add it to the
        // result; if the top element has a next element add it to the heap
        ListNode? resultHead = null;
        ListNode? resultTail = null;
        while (minHeap.Count > 0)
        {
            ListNode node = minHeap.Dequeue();
            if (resultTail == null)
            {
                resultHead = node;
                resultTail = node;
            }
            else
            {
                resultTail.Next = node;
                resultTail = resultTail.Next;
            }

            if (node.Next != null)
            {
                minHeap.Enqueue(node.Next, node.Next.Val);
            }
        }

        return resultHead;
    }
}
