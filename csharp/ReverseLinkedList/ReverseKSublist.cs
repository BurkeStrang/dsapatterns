namespace DsaPatterns.ReverseLinkedList;

// Given the head of a LinkedList and a number ‘k’,
// reverse every ‘k’ sized sub-list starting from the head.
//
// If, in the end, you are left with a sub-list with less than ‘k’ elements,
// reverse it too.

internal static class ReverseKSublist
{
    internal static ListNode? ReverseKSub(ListNode? head, int k)
    {
        if (k <= 1 || head == null)
        {
            return head;
        }

        ListNode? current = head;
        ListNode? previous = null;
        while (true)
        {
            ListNode? lastNodeOfPreviousPart = previous;
            // after reversing the list 'current' will become the last node of
            // the sub-list
            ListNode lastNodeOfSubList = current;
            ListNode? next; // will be used to temporarily store the next node
            // reverse 'k' nodes
            for (int i = 0; current != null && i < k; i++)
            {
                next = current.Next;
                current.Next = previous;
                previous = current;
                current = next;
            }

            // connect with the previous part
            if (lastNodeOfPreviousPart != null)
            {
                // 'previous' is now the first node of the sub-list
                lastNodeOfPreviousPart.Next = previous;
            }
            else
            {
                // this means we are changing the first node (head) of the list
                head = previous;
            }

            // connect with the next part
            lastNodeOfSubList.Next = current;

            if (current == null) // break, if we've reached the end of the list
            {
                break;
            }

            // prepare for the next sub-list
            previous = lastNodeOfSubList;
        }

        return head;
    }
}
