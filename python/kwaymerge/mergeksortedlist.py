"""
Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.
Example 1:
Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]

Example 2:
Input: L1=[5, 8, 9], L2=[1, 7]
Output: [1, 5, 7, 8, 9]
"""

import heapq

from common.list import ListNode


def merge(lists: list[ListNode | None]) -> ListNode | None:
    """Merges the given lists into one sorted list."""
    # a min heap of (value of a node, index of its list); the nodes are
    # looked up through 'heads', the first node not yet merged of each list
    heads = list(lists)
    min_heap: list[tuple[int, int]] = []

    # put the root of each list in the min heap
    for i, head in enumerate(heads):
        if head is not None:
            heapq.heappush(min_heap, (head.value, i))

    # take the smallest (top) element form the min-heap and add it to the
    # result; if the top element has a next element add it to the heap
    result_head: ListNode | None = None
    result_tail: ListNode | None = None
    while min_heap:
        _, i = heapq.heappop(min_heap)
        node = heads[i]
        assert node is not None  # only lists with nodes left are in the heap
        heads[i] = node.next
        if result_tail is None:
            result_head = node
        else:
            result_tail.next = node
        result_tail = node

        next_node = heads[i]
        if next_node is not None:
            heapq.heappush(min_heap, (next_node.value, i))

    return result_head
