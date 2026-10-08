namespace DsaPatterns.MonotonicStack;

internal class ListNode(int val, ListNode? next = null)
{
    public int Val { get; set; } = val;
    public ListNode? Next { get; set; } = next;
}

// Shared helpers for the monotonic stack problems.
internal static class Shared
{
    // Builds a linked list from the values, to keep test data compact.
    internal static ListNode? BuildList(int[] vals)
    {
        ListNode? head = null;
        for (int i = vals.Length - 1; i >= 0; i--)
        {
            head = new ListNode(vals[i], head);
        }

        return head;
    }

    // Converts a linked list to a list of ints so two lists can be compared.
    internal static List<int> ListToValues(ListNode? head)
    {
        List<int> res = [];
        while (head != null)
        {
            res.Add(head.Val);
            head = head.Next;
        }

        return res;
    }

    internal static string Format(IEnumerable<int> nums)
    {
        return $"[{string.Join(", ", nums)}]";
    }
}
