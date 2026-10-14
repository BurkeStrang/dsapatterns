"""
Given the head of a Singly LinkedList, write a method to check if the
LinkedList is a palindrome or not.

Your algorithm should use constant space and the input LinkedList should be
in the original form once the algorithm is finished.
The algorithm should have O(N) time complexity where ‘N’ is the number of
nodes in the LinkedList.

Example 1:

Input: 2 -> 4 -> 6 -> 4 -> 2 -> null
Output: true
Example 2:

Input: 2 -> 4 -> 6 -> 4 -> 2 -> 2 -> null
Output: false
Constraints:

The number of nodes in the list is in the range [].
0 <= Node.val <= 9
"""

from common.list import ListNode


def reverse(head: ListNode | None) -> ListNode | None:
    prev = None
    while head is not None:
        next = head.next
        head.next = prev
        prev = head
        head = next
    return prev


def is_palindrome(head: ListNode | None) -> bool:
    if head is None or head.next is None:
        return True

    # find middle of the LinkedList
    slow: ListNode | None = head
    fast: ListNode | None = head
    while fast is not None and fast.next is not None:
        assert slow is not None  # slow is behind fast, so it is never None
        slow = slow.next
        fast = fast.next.next

    head_second_half = reverse(slow)  # reverse the second half
    # store the head of reversed part to revert back later
    copy_head_second_half = head_second_half

    # compare the first and the second half
    first: ListNode | None = head
    while first is not None and head_second_half is not None:
        if first.value != head_second_half.value:
            break  # not a palindrome
        first = first.next
        head_second_half = head_second_half.next

    reverse(copy_head_second_half)  # revert the reverse of the second half

    # if both halves match, one of them ran out
    return first is None or head_second_half is None
