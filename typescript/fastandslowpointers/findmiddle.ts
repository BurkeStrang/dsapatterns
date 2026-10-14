// Given the head of a singly LinkedList, return the middle node. If the list
// has an even number of nodes, return the second of the two middle nodes.

import type { ListNode } from "../common/list.ts";

export function findMiddle(head: ListNode | null): ListNode | null {
  let slow = head;
  let fast = head;
  // slow is behind fast, so checking fast is enough; slow is checked only to
  // tell the type checker it is there
  while (fast !== null && fast.next !== null && slow !== null) {
    slow = slow.next;
    fast = fast.next.next;
  }
  return slow;
}
