// Given an unsorted array of numbers, find Kth smallest number in it.
// Please note that it is the Kth smallest number in the sorted order,
// not the Kth distinct element.
// Note: For a detailed discussion about different approaches to solve this
// problem,
// take a look at Kth Smallest Number.
//
// Example 1:
// Input: [1, 5, 12, 2, 11, 5], K = 3
// Output: 5
// Explanation: The 3rd smallest number is '5', as the first two smaller numbers
// are [1, 2].
//
// Example 2:
// Input: [1, 5, 12, 2, 11, 5], K = 4
// Output: 5
// Explanation: The 4th smallest number is '5', as the first three small numbers
// are [1, 2, 5].
//
// Example 3:
// Input: [5, 12, 11, -1, 12], K = 3
// Output: 11
// Explanation: The 3rd smallest number is '11', as the first two small numbers
// are [5, -1].

import { Heap } from "../common/heap.ts";

export function findKthSmallestNumber(nums: number[], k: number): number {
  // a max heap of the 'k' smallest numbers seen so far
  const maxHeap = new Heap<number>((a, b) => a > b);

  // put first k numbers in the max heap
  for (const num of nums.slice(0, k)) {
    maxHeap.push(num);
  }

  // go through the remaining numbers of the array, if the number from the
  // array is smaller than the top (biggest) number of the heap, remove the
  // top number from heap and add the number from array
  for (const num of nums.slice(k)) {
    const top = maxHeap.peek();
    if (top !== undefined && num < top) {
      maxHeap.pop();
      maxHeap.push(num);
    }
  }

  // the root of the heap has the Kth smallest number
  return maxHeap.peek() ?? -1;
}
