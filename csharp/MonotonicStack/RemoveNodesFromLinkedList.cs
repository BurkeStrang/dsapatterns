namespace DsaPatterns.MonotonicStack;

// Given the head node of a singly linked list, modify the list such that any
// node that has a node with a greater value to its right gets removed. The
// function should return the head of the modified list.
//
// Examples:
// Input: 5 -> 3 -> 7 -> 4 -> 2 -> 1
// Output: 7 -> 4 -> 2 -> 1
// Explanation: 5 and 3 are removed as they have nodes with larger values to
// their right.
//
// Input: 1 -> 2 -> 3 -> 4 -> 5
// Output: 5
// Explanation: 1, 2, 3, and 4 are removed as they have nodes with larger values
// to their right.
//
// Input: 5 -> 4 -> 3 -> 2 -> 1
// Output: 5 -> 4 -> 3 -> 2 -> 1
// Explanation: None of the nodes are removed as none of them have nodes with
// larger values to their right.
//
// Constraints:
// The number of the nodes in the given list is in the range [1, 105].
// 1 <= Node.val <= 105

internal static class RemoveNodesFromLinkedList
{
    internal static ListNode? RemoveNodes(ListNode? head)
    {
        // Create an empty stack to store nodes in descending order
        List<ListNode> stack = [];
        ListNode? cur = head;

        while (cur != null)
        {
            while (stack.Count > 0 && stack[^1].Val < cur.Val)
            {
                stack.RemoveAt(stack.Count - 1); // Pop from the stack
            }

            if (stack.Count > 0)
            {
                // Update the next pointer of the top node in the stack
                stack[^1].Next = cur;
            }

            stack.Add(cur); // Push the current node onto the stack
            cur = cur.Next;
        }

        if (stack.Count == 0)
        {
            return null;
        }

        // Return the head of the modified list (the bottom of the stack)
        return stack[0];
    }
}
