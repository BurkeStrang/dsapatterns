namespace DsaPatterns.FastAndSlowPointers;

// Given the head of a Singly LinkedList, write a function to determine if the
// LinkedList has a cycle in it or not.

internal static class LinkedListCycle
{
    internal static bool HasCycle(ListNode? head)
    {
        ListNode? slow = head;
        ListNode? fast = head;
        while (fast != null && fast.Next != null)
        {
            fast = fast.Next.Next;
            slow = slow!.Next;
            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
}
