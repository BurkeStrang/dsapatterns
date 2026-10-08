namespace DsaPatterns.ReverseLinkedList;

// Given the head of a Singly LinkedList, reverse the LinkedList.
// Write a function to return the new head of the reversed LinkedList.

internal static class Reverse
{
    internal static ListNode? ReverseList(ListNode? head)
    {
        ListNode? previous = null;
        ListNode? curr = head;
        while (curr != null)
        {
            ListNode? temp = curr.Next;
            curr.Next = previous;
            previous = curr;
            curr = temp;
        }

        return previous;
    }
}
