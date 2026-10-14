// Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.
// Example 1:
// Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
// Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]
//
// Example 2:
// Input: L1=[5, 8, 9], L2=[1, 7]
// Output: [1, 5, 7, 8, 9]

import { Heap } from "../common/heap.ts";
import type { ListNode } from "../common/list.ts";

// merge merges the given lists into one sorted list.
export function merge(lists: (ListNode | null)[]): ListNode | null {
  // a min heap of the first node not yet merged of each list
  const minHeap = new Heap<ListNode>((a, b) => a.value < b.value);

  // put the root of each list in the min heap
  for (const head of lists) {
    if (head !== null) {
      minHeap.push(head);
    }
  }

  // take the smallest (top) element form the min-heap and add it to the
  // result; if the top element has a next element add it to the heap
  let resultHead: ListNode | null = null;
  let resultTail: ListNode | null = null;
  for (let node = minHeap.pop(); node !== undefined; node = minHeap.pop()) {
    if (resultTail === null) {
      resultHead = node;
    } else {
      resultTail.next = node;
    }
    resultTail = node;

    if (node.next !== null) {
      minHeap.push(node.next);
    }
  }

  return resultHead;
}
