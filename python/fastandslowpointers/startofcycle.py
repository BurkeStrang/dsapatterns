"""
Given the head of a singly LinkedList that contains a cycle, find the node
where the cycle starts. Returns None if there is no cycle.
"""

from common.list import ListNode


def find_cycle_start(head: ListNode | None) -> ListNode | None:
    slow = head
    fast = head
    while fast is not None and fast.next is not None:
        assert slow is not None  # slow is behind fast, so it is never None
        slow = slow.next
        fast = fast.next.next
        if slow is fast:
            break  # found the cycle

    if fast is None or fast.next is None:
        return None  # no cycle

    # move both pointers one step at a time; they meet at the start
    slow = head
    while slow is not fast:
        assert slow is not None and fast is not None  # both are in the cycle
        slow = slow.next
        fast = fast.next
    return slow
