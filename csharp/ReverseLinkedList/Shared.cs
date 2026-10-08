namespace DsaPatterns.ReverseLinkedList;

internal class ListNode(int val, ListNode? next = null)
{
    public int Val { get; set; } = val;
    public ListNode? Next { get; set; } = next;
}

// Shared helpers for the reverse linked list problems.
internal static class Shared
{
    // Builds a linked list from the values, to keep test data compact.
    internal static ListNode? ToList(int[] vals)
    {
        ListNode? head = null;
        for (int i = vals.Length - 1; i >= 0; i--)
        {
            head = new ListNode(vals[i], head);
        }

        return head;
    }

    // Collects the values of a full list so two lists can be compared.
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
