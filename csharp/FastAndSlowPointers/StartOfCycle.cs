namespace DsaPatterns.FastAndSlowPointers;

internal static class StartOfCycle
{
    internal static ListNode? FindCycleStart(ListNode? head)
    {
        if (head == null)
        {
            return null;
        }

        ListNode? slow = head;
        ListNode? fast = head;
        while (fast != null && fast.Next != null)
        {
            slow = slow!.Next;
            fast = fast.Next.Next;
            if (slow == fast)
            {
                break;
            }
        }

        if (fast == null || fast.Next == null)
        {
            return null;
        }

        slow = head;
        while (slow != fast)
        {
            slow = slow!.Next;
            fast = fast!.Next;
        }

        return slow;
    }
}
