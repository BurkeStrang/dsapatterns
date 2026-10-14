// Given the head of a LinkedList and a number ‘k’,
// reverse every alternating ‘k’ sized sub-list starting from the head.
// If, in the end, you are left with a sub-list with less than ‘k’ elements,
// reverse it too.
//
// Constraints:
// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000

import type { ListNode } from "../common/list.ts";

export function reverseAlt(head: ListNode | null, k: number): ListNode | null {
  if (k <= 1 || head === null) {
    return head;
  }

  let current: ListNode | null = head;
  let previous: ListNode | null = null;
  while (current !== null) {
    // break if we've reached the end of the list
    const lastNodeOfPreviousPart = previous;
    // after reversing the LinkedList 'current' will become the last node of
    // the sub-list
    const lastNodeOfSubList: ListNode = current;

    // reverse 'k' nodes
    for (let i = 0; current !== null && i < k; i++) {
      const next: ListNode | null = current.next;
      current.next = previous;
      previous = current;
      current = next;
    }

    // connect with the previous part
    if (lastNodeOfPreviousPart !== null) {
      lastNodeOfPreviousPart.next = previous;
    } else {
      // this means we are changing the first node (head) of the LinkedList
      head = previous;
    }

    // connect with the next part
    lastNodeOfSubList.next = current;

    // skip 'k' nodes
    for (let i = 0; current !== null && i < k; i++) {
      previous = current;
      current = current.next;
    }
  }
  return head;
}
