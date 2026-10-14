"""
Given the head of a LinkedList with a cycle, find the length of the cycle.
Returns 0 if there is no cycle.
"""

from common.list import ListNode


def calc_cycle_distance(slow: ListNode) -> int:
    current = slow.next
    current_count = 1
    while current is not slow and current is not None:
        current = current.next
        current_count += 1
    return current_count


def find_cycle_length(head: ListNode | None) -> int:
    slow = head
    fast = head
    while fast is not None and fast.next is not None:
        assert slow is not None  # slow is behind fast, so it is never None
        slow = slow.next
        fast = fast.next.next
        if slow is fast and slow is not None:  # found the cycle
            return calc_cycle_distance(slow)
    return 0
