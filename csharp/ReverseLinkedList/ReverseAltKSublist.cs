namespace DsaPatterns.ReverseLinkedList;

// Given the head of a LinkedList and a number ‘k’,
// reverse every alternating ‘k’ sized sub-list starting from the head.
// If, in the end, you are left with a sub-list with less than ‘k’ elements,
// reverse it too.
//
// Constraints:
// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000

internal static class ReverseAltKSublist
{
    internal static ListNode? ReverseAlt(ListNode? head, int k)
    {
        if (k <= 1 || head == null)
        {
            return head;
        }

        ListNode? current = head;
        ListNode? previous = null;
        while (current != null) // break if we've reached the end of the list
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

            // skip 'k' nodes
            for (int i = 0; current != null && i < k; i++)
            {
                previous = current;
                current = current.Next;
            }
        }

        return head;
    }
}
