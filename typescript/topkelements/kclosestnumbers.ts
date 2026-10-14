// Given a sorted number array and two integers ‘K’ and ‘X’,
// find ‘K’ closest numbers to ‘X’ in the array.
// Return the numbers in the sorted order.
// ‘X’ is not necessarily present in the array.
//
// Example 1:
// Input: [5, 6, 7, 8, 9], K = 3, X = 7
// Output: [6, 7, 8]
//
// Example 2:
// Input: [2, 4, 5, 6, 9], K = 3, X = 6
// Output: [4, 5, 6]
//
// Example 3:
// Input: [2, 4, 5, 6, 9], K = 3, X = 10
// Output: [5, 6, 9]

import { Heap } from "../common/heap.ts";

// binarySearch returns the index of the target, or of the number closest to
// it from below when the target is not in the array
export function binarySearch(arr: number[], target: number): number {
  let low = 0;
  let high = arr.length - 1;
  while (low <= high) {
    const mid = low + Math.floor((high - low) / 2);
    if (arr[mid] === target) {
      return mid;
    }
    if (arr[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  if (low > 0) {
    return low - 1;
  }
  return low;
}

export function findClosestElements(
  arr: number[],
  k: number,
  x: number,
): number[] {
  const index = binarySearch(arr, x);
  // 'low' should not be less than zero
  const low = Math.max(index - k, 0);
  // 'high' should not be greater the size of the array
  const high = Math.min(index + k, arr.length - 1);

  // a min heap of indices, ordered by the absolute difference of their
  // number from 'x', then by index
  const distance = (i: number): number => Math.abs(arr[i] - x);
  const minHeap = new Heap<number>(
    (a, b) =>
      distance(a) < distance(b) || (distance(a) === distance(b) && a < b),
  );
  // add all candidate elements to the min heap, sorted by their absolute
  // difference from 'x'
  for (let i = low; i <= high; i++) {
    minHeap.push(i);
  }

  // we need the top 'k' elements having the smallest difference from 'x'
  const result: number[] = [];
  for (let i = 0; i < k; i++) {
    const top = minHeap.pop();
    if (top === undefined) {
      break;
    }
    result.push(arr[top]);
  }

  return result.sort((a, b) => a - b);
}
