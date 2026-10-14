// Given ‘M’ sorted arrays, find the smallest range that includes at least one
// number from each of the ‘M’ lists.
// Example 1:
// Input: L1=[1, 5, 8], L2=[4, 12], L3=[7, 8, 10]
// Output: [4, 7]
// Explanation: The range [4, 7] includes 5 from L1, 4 from L2 and 7 from L3.
//
// Example 2:
// Input: L1=[1, 9], L2=[4, 12], L3=[7, 10, 16]
// Output: [9, 12]
// Explanation: The range [9, 12] includes 9 from L1, 12 from L2 and 10 from L3

import { Heap } from "../common/heap.ts";

// a number, the array it came from, and its index in that array
interface Entry {
  num: number;
  arrayIndex: number;
  elementIndex: number;
}

export function findSmallestRange(lists: number[][]): number[] {
  // a min heap of the entries, so the smallest number is on top
  const minHeap = new Heap<Entry>((a, b) => a.num < b.num);
  let rangeStart = 0;
  let rangeEnd = Infinity;
  let currentMaxNumber = -Infinity;

  // put the 1st element of each array in the min heap
  lists.forEach((numbers, i) => {
    if (numbers.length > 0) {
      minHeap.push({ num: numbers[0], arrayIndex: i, elementIndex: 0 });
      currentMaxNumber = Math.max(currentMaxNumber, numbers[0]);
    }
  });

  // take the smallest (top) element form the min heap, if it gives us
  // smaller range, update the ranges; if the array of the top element has
  // more elements, insert the next element in the heap.
  // we stop as soon as one of the arrays has run out, the heap then holds
  // fewer numbers than there are arrays
  while (minHeap.size === lists.length) {
    const top = minHeap.pop();
    if (top === undefined) {
      break;
    }
    const { num, arrayIndex } = top;
    if (rangeEnd - rangeStart > currentMaxNumber - num) {
      rangeStart = num;
      rangeEnd = currentMaxNumber;
    }

    const elementIndex = top.elementIndex + 1;
    if (elementIndex < lists[arrayIndex].length) {
      const next = lists[arrayIndex][elementIndex];
      minHeap.push({ num: next, arrayIndex, elementIndex });
      currentMaxNumber = Math.max(currentMaxNumber, next);
    }
  }

  return [rangeStart, rangeEnd];
}
