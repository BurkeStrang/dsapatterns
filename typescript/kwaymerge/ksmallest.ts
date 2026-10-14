// Given ‘M’ sorted arrays, find the K’th smallest number among all the arrays.
//
// Example 1:
// Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4], K=5
// Output: 4
// Explanation: The 5th smallest number among all the arrays is 4, this can be
// verified from
// the merged list of all the arrays: [1, 2, 3, 3, 4, 6, 6, 7, 8]
//
// Example 2:
// Input: L1=[5, 8, 9], L2=[1, 7], K=3
// Output: 7
// Explanation: The 3rd smallest number among all the arrays is 7.

import { Heap } from "../common/heap.ts";

// a number, the array it came from, and its index in that array
interface Entry {
  num: number;
  arrayIndex: number;
  elementIndex: number;
}

export function findKthSmallest(lists: number[][], k: number): number {
  // a min heap of the entries, so the smallest number is on top
  const minHeap = new Heap<Entry>((a, b) => a.num < b.num);

  // put the 1st element of each array in the min heap
  lists.forEach((numbers, i) => {
    if (numbers.length > 0) {
      minHeap.push({ num: numbers[0], arrayIndex: i, elementIndex: 0 });
    }
  });

  // take the smallest (top) element form the min heap, if the running count
  // is equal to k return the number if the array of the top element has
  // more elements, add the next element to the heap
  let numberCount = 0;
  let result = 0;
  for (let top = minHeap.pop(); top !== undefined; top = minHeap.pop()) {
    const { num, arrayIndex } = top;
    result = num;
    numberCount++;
    if (numberCount === k) {
      break;
    }
    const elementIndex = top.elementIndex + 1;
    if (elementIndex < lists[arrayIndex].length) {
      minHeap.push({
        num: lists[arrayIndex][elementIndex],
        arrayIndex,
        elementIndex,
      });
    }
  }
  return result;
}
