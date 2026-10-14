// Given two sorted arrays in descending order,
// find ‘K’ pairs with the largest sum where each pair consists of numbers from
// both the arrays.
//
// Example 1:
// Input: nums1=[9, 8, 2], nums2=[6, 3, 1], K=3
// Output: [9, 3], [9, 6], [8, 6]
// Explanation: These 3 pairs have the largest sum. No other pair has a sum
// larger than any of these.
//
// Example 2:
// Input: nums1=[5, 2, 1], nums2=[2, -1], K=3
// Output: [5, 2], [5, -1], [2, 2]

import { Heap } from "../common/heap.ts";

// a pair with its sum
type Entry = [sum: number, first: number, second: number];

// smallerFirst orders entries for a min heap: the smallest sum on top, and
// pairs with the same sum in the order of their numbers
function smallerFirst(a: Entry, b: Entry): boolean {
  for (let i = 0; i < a.length; i++) {
    if (a[i] !== b[i]) {
      return a[i] < b[i];
    }
  }
  return false;
}

// findKLargestPairs finds k largest pairs.
export function findKLargestPairs(
  nums1: number[],
  nums2: number[],
  k: number,
): number[][] {
  // a min heap of the pairs, so the pair with the smallest sum is on top
  const minHeap = new Heap<Entry>(smallerFirst);
  for (let i = 0; i < Math.min(k, nums1.length); i++) {
    for (let j = 0; j < Math.min(k, nums2.length); j++) {
      const sum = nums1[i] + nums2[j];
      if (minHeap.size < k) {
        minHeap.push([sum, nums1[i], nums2[j]]);
        continue;
      }

      // if the sum of the two numbers from the two arrays is smaller than
      // the smallest (top) element of the heap, we can 'break' here.
      const smallest = minHeap.peek();
      if (smallest !== undefined && sum < smallest[0]) {
        break;
      }

      // we've a pair with a larger sum, remove top and insert this pair in
      // heap
      minHeap.pop();
      minHeap.push([sum, nums1[i], nums2[j]]);
    }
  }

  const result: number[][] = [];
  for (let top = minHeap.pop(); top !== undefined; top = minHeap.pop()) {
    result.push([top[1], top[2]]);
  }
  return result;
}
