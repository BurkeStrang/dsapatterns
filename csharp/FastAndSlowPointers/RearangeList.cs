namespace DsaPatterns.FastAndSlowPointers;

internal static class RearangeList
{
    internal static ListNode? Rearange(ListNode? head)
    {
        if (head == null)
        {
            return null;
        }

        // find middle
        ListNode? slow = head;
        ListNode? fast = head;
        while (fast != null && fast.Next != null)
        {
            slow = slow!.Next;
            fast = fast.Next.Next;
        }

        // reverse second half
        ListNode? curr = slow;
        ListNode? prev = null;
        while (curr != null)
        {
            ListNode? next = curr.Next;
            curr.Next = prev;
            prev = curr;
            curr = next;
        }

        // set every other one as the reverse second half
        ListNode first = head;
        ListNode second = prev!;
        while (second.Next != null)
        {
            ListNode tmp1 = first.Next!;
            ListNode tmp2 = second.Next;
            first.Next = second;
            second.Next = tmp1;
            first = tmp1;
            second = tmp2;
        }

        return head;
    }
}
