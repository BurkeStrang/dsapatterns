"""
Given the head of a singly LinkedList, change the list in place so that
the nodes from the second half are put, in reverse order, between the nodes
of the first half. So 1 -> 2 -> 3 -> 4 becomes 1 -> 4 -> 2 -> 3.
"""

from common.list import ListNode


def rearange_list(head: ListNode | None) -> ListNode | None:
    if head is None:
        return None

    # find middle
    slow: ListNode | None = head
    fast: ListNode | None = head
    while fast is not None and fast.next is not None:
        assert slow is not None  # slow is behind fast, so it is never None
        slow = slow.next
        fast = fast.next.next

    # reverse second half
    current = slow
    prev: ListNode | None = None
    while current is not None:
        next = current.next
        current.next = prev
        prev = current
        current = next

    # set every other one as the reverse second half
    first: ListNode | None = head
    second = prev
    while first is not None and second is not None and second.next is not None:
        tmp1 = first.next
        tmp2 = second.next
        first.next = second
        second.next = tmp1
        first = tmp1
        second = tmp2
    return head
