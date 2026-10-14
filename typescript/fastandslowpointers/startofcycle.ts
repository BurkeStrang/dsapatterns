// Given the head of a singly LinkedList that contains a cycle, find the node
// where the cycle starts. Returns None if there is no cycle.

import type { ListNode } from "../common/list.ts";

export function findCycleStart(head: ListNode | null): ListNode | null {
  let slow = head;
  let fast = head;
  // slow is behind fast, so checking fast is enough; slow is checked only to
  // tell the type checker it is there
  while (fast !== null && fast.next !== null && slow !== null) {
    slow = slow.next;
    fast = fast.next.next;
    if (slow === fast) {
      break; // found the cycle
    }
  }

  if (fast === null || fast.next === null) {
    return null; // no cycle
  }

  // move both pointers one step at a time; they meet at the start
  slow = head;
  while (slow !== fast && slow !== null && fast !== null) {
    slow = slow.next;
    fast = fast.next;
  }
  return slow;
}
