// Given the head of a singly LinkedList, determine if it has a cycle in it.

import type { ListNode } from "../common/list.ts";

export function hasCycle(head: ListNode | null): boolean {
  let slow = head;
  let fast = head;
  // slow is behind fast, so checking fast is enough; slow is checked only to
  // tell the type checker it is there
  while (fast !== null && fast.next !== null && slow !== null) {
    fast = fast.next.next;
    slow = slow.next;
    if (slow === fast) {
      return true; // found the cycle
    }
  }
  return false;
}
