namespace DsaPatterns.FastAndSlowPointers;

internal class ListNode(int val, ListNode? next = null)
{
    public int Val { get; set; } = val;
    public ListNode? Next { get; set; } = next;
}

// Shared helpers for the fast and slow pointers problems.
internal static class Shared
{
    // Builds a linked list from the values. If cycleStart is not -1 the last
    // node is linked back to the node at that index, creating a cycle.
    internal static ListNode? ToList(int[] vals, int cycleStart = -1)
    {
        if (vals.Length == 0)
        {
            return null;
        }

        ListNode[] nodes = vals.Select(val => new ListNode(val)).ToArray();
        for (int i = 0; i < nodes.Length - 1; i++)
        {
            nodes[i].Next = nodes[i + 1];
        }

        if (cycleStart != -1)
        {
            nodes[^1].Next = nodes[cycleStart];
        }

        return nodes[0];
    }

    // Collects the values of a full (non-cyclic) list so two lists can be
    // compared.
    internal static List<int> ToValues(ListNode? head)
    {
        List<int> vals = [];
        while (head != null)
        {
            vals.Add(head.Val);
            head = head.Next;
        }

        return vals;
    }

    internal static string Format(IEnumerable<int> nums)
    {
        return $"[{string.Join(", ", nums)}]";
    }
}
