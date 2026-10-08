namespace DsaPatterns.ReverseLinkedList;

// Given the head of a Singly LinkedList and a number ‘k’,
// rotate the LinkedList to the right by ‘k’ nodes.

// Constraints:
//
// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 10^9

internal static class RotateLinkedList
{
    internal static ListNode? Rotate(ListNode? head, int rotations)
    {
        // base cases
        if (head == null || head.Next == null || rotations <= 0)
        {
            return head;
        }

        // find the length and the last node of the list
        ListNode lastNode = head;
        int listLength = 1;
        while (lastNode.Next != null)
        {
            lastNode = lastNode.Next;
            listLength++;
        }

        // connect the last node with the head to a circular list
        lastNode.Next = head;
        // no need to do rotations more than the length of the list
        rotations %= listLength;
        int skipLength = listLength - rotations;
        ListNode lastNodeOfRotatedList = head;
        for (int i = 0; i < skipLength - 1; i++)
        {
            lastNodeOfRotatedList = lastNodeOfRotatedList.Next!;
        }

        // 'lastNodeOfRotatedList.Next' is pointing to the sub-list of 'k'
        // ending nodes
        head = lastNodeOfRotatedList.Next;
        lastNodeOfRotatedList.Next = null;
        return head;
    }
}
