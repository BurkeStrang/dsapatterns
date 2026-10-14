"""
Given the head of a singly LinkedList, return the middle node. If the list
has an even number of nodes, return the second of the two middle nodes.
"""

from common.list import ListNode


def find_middle(head: ListNode | None) -> ListNode | None:
    slow = head
    fast = head
    while fast is not None and fast.next is not None:
        assert slow is not None  # slow is behind fast, so it is never None
        slow = slow.next
        fast = fast.next.next
    return slow
