// Given the head of a LinkedList with a cycle, find the length of the cycle.
// Returns 0 if there is no cycle.

import type { ListNode } from "../common/list.ts";

export function calcCycleDistance(slow: ListNode): number {
  let current = slow.next;
  let currentCount = 1;
  while (current !== slow && current !== null) {
    current = current.next;
    currentCount++;
  }
  return currentCount;
}

export function findCycleLength(head: ListNode | null): number {
  let slow = head;
  let fast = head;
  // slow is behind fast, so checking fast is enough; slow is checked only to
  // tell the type checker it is there
  while (fast !== null && fast.next !== null && slow !== null) {
    slow = slow.next;
    fast = fast.next.next;
    if (slow === fast && slow !== null) {
      return calcCycleDistance(slow); // found the cycle
    }
  }
  return 0;
}
