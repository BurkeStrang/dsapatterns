// Given an unsorted array of numbers,
// find the top ‘K’ frequently occurring numbers in it.
//
// Example 1:
// Input: [1, 3, 5, 12, 11, 12, 11], K = 2
// Output: [12, 11]
// Explanation: Both '11' and '12' appeared twice.
//
// Example 2:
// Input: [5, 12, 11, 3, 11], K = 2
// Output: [11, 5] or [11, 12] or [11, 3]
// Explanation: Only '11' appeared twice; all other numbers appeared once.

import { Heap } from "../common/heap.ts";

export function findTopKFrequentNumbers(nums: number[], k: number): number[] {
  // Find the frequency of each number
  const numFrequencyMap = new Map<number, number>();
  for (const n of nums) {
    numFrequencyMap.set(n, (numFrequencyMap.get(n) ?? 0) + 1);
  }

  // Create a min heap to store [frequency, number] entries
  const minFreqHeap = new Heap<[number, number]>(
    (a, b) => a[0] < b[0] || (a[0] === b[0] && a[1] < b[1]),
  );

  // Go through all numbers in numFrequencyMap and push them into the min
  // heap. If the heap size is more than k, remove the smallest (top) entry
  for (const [num, frequency] of numFrequencyMap) {
    minFreqHeap.push([frequency, num]);
    if (minFreqHeap.size > k) {
      minFreqHeap.pop();
    }
  }

  // Create a list of top k frequent numbers; the heap gives the least
  // frequent first, so fill the list from the back
  const topNumbers = new Array<number>(minFreqHeap.size).fill(0);
  for (let i = topNumbers.length - 1; i >= 0; i--) {
    topNumbers[i] = minFreqHeap.pop()?.[1] ?? 0;
  }
  return topNumbers;
}
