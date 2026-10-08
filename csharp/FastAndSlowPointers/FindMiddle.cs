namespace DsaPatterns.FastAndSlowPointers;

internal static class FindMiddle
{
    internal static ListNode? Middle(ListNode? head)
    {
        ListNode? slow = head;
        ListNode? fast = head;
        while (fast != null && fast.Next != null)
        {
            slow = slow!.Next;
            fast = fast.Next.Next;
        }

        return slow;
    }
}
