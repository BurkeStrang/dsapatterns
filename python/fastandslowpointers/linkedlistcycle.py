"""
Given the head of a singly LinkedList, determine if it has a cycle in it.
"""

from common.list import ListNode


def has_cycle(head: ListNode | None) -> bool:
    slow = head
    fast = head
    while fast is not None and fast.next is not None:
        fast = fast.next.next
        assert slow is not None  # slow is behind fast, so it is never None
        slow = slow.next
        if slow is fast:
            return True  # found the cycle
    return False
