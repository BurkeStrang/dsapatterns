#include "monotonicstack/shared.h"

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

ListNode *remove_nodes
(
    ListNode *head
)
{
    // Create an empty stack to store nodes in descending order. It can never
    // hold more nodes than the list has.
    int length = 0;
    for (ListNode *node = head; node != NULL; node = node->next)
    {
        length++;
    }
    ListNode **stack = malloc(((size_t)length + 1) * sizeof(ListNode *));
    int stack_len = 0;

    ListNode *cur = head;
    while (cur != NULL)
    {
        while (stack_len > 0 && stack[stack_len - 1]->val < cur->val)
        {
            stack_len--; // Pop from the stack
        }

        if (stack_len > 0)
        {
            // Update the next pointer of the top node in the stack
            stack[stack_len - 1]->next = cur;
        }

        stack[stack_len++] = cur; // Push the current node onto the stack
        cur = cur->next;
    }

    // Return the head of the modified list (the bottom of the stack), or NULL
    // if the stack is empty
    ListNode *result = stack_len == 0 ? NULL : stack[0];
    free(stack);
    return result;
}
