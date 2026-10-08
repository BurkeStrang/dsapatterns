namespace DsaPatterns.FastAndSlowPointers;

// Given the head of a LinkedList with a cycle, find the length of the cycle.

internal static class FindCycleLength
{
    internal static int CycleLength(ListNode? head)
    {
        ListNode? slow = head;
        ListNode? fast = head;
        while (fast != null && fast.Next != null)
        {
            slow = slow!.Next;
            fast = fast.Next.Next;
            if (slow == fast)
            {
                return CalcCycleDistance(slow!);
            }
        }

        return 0;
    }

    private static int CalcCycleDistance(ListNode slow)
    {
        ListNode? current = slow.Next;
        int currentCount = 1;
        while (current != slow)
        {
            current = current!.Next;
            currentCount++;
        }

        return currentCount;
    }
}
