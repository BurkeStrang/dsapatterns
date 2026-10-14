// Given an unsorted array of numbers, find the ‘K’ largest numbers in it.
//
// Example 1:
// Input: [3, 1, 5, 12, 2, 11], K = 3
// Output: [5, 12, 11]
//
// Example 2:
// Input: [5, 12, 11, -1, 12], K = 3
// Output: [12, 11, 12]

import { Heap } from "../common/heap.ts";

export function findKLargestNumbers(nums: number[], k: number): number[] {
  // a min heap of the 'K' largest numbers seen so far
  const minHeap = new Heap<number>((a, b) => a < b);

  // put first 'K' numbers in the min heap
  for (const num of nums.slice(0, k)) {
    minHeap.push(num);
  }

  // go through the remaining numbers of the array, if the number from the
  // array is bigger than the top (smallest) number of the min-heap, remove
  // the top number from heap and add the number from array
  for (const num of nums.slice(k)) {
    const top = minHeap.peek();
    if (top !== undefined && num > top) {
      minHeap.pop();
      minHeap.push(num);
    }
  }

  // the heap has the top 'K' numbers, return them in a list
  return minHeap.toArray();
}
