namespace DsaPatterns.ReverseLinkedList;

// Given the head of a LinkedList and two positions ‘p’ and ‘q’,
// reverse the LinkedList from position ‘p’ to ‘q’.

internal static class ReverseSublist
{
    internal static ListNode? ReverseSub(ListNode? head, int p, int q)
    {
        if (p == q || head == null)
        {
            return head;
        }

        // after skipping 'p-1' nodes, current will point to 'p'th node
        ListNode? current = head;
        ListNode? previous = null;
        for (int i = 0; current != null && i < p - 1; i++)
        {
            previous = current;
            current = current.Next;
        }

        if (current == null) // 'p' is past the end of the list
        {
            return head;
        }

        // we are interested in three parts of the LinkedList, part before
        // index 'p', part between 'p' and 'q', and the part after index 'q'
        // points to the node at index 'p-1'
        ListNode? lastNodeOfFirstPart = previous;
        // after reversing the LinkedList 'current' will become the last node
        // of the sub-list
        ListNode lastNodeOfSubList = current;
        ListNode? next; // will be used to temporarily store the next node
        // reverse nodes between 'p' and 'q'
        for (int i = 0; current != null && i < q - p + 1; i++)
        {
            next = current.Next;
            current.Next = previous;
            previous = current;
            current = next;
        }

        // connect with the first part
        if (lastNodeOfFirstPart != null)
        {
            // 'previous' is now the first node of the sub-list
            lastNodeOfFirstPart.Next = previous;
        }
        else
        {
            // this means p == 1 i.e., we are changing the first node (head) of
            // the LinkedList
            head = previous;
        }

        // connect with the last part
        lastNodeOfSubList.Next = current;
        return head;
    }
}
