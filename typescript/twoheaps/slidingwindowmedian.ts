// Given an array of numbers and a number 'k', find the median of all the 'k'
// sized sub-arrays (or windows) of the array.
//
// Example 1:
// Input: nums=[1, 2, -1, 3, 5], k = 2
// Output: [1.5, 0.5, 1.0, 4.0]
//
// Example 2:
// Input: nums=[1, 2, -1, 3, 5], k = 3
// Output: [1.0, 2.0, 3.0]

import { Heap } from "../common/heap.ts";

export class Window {
  // the smaller half of the window, largest on top
  readonly maxHeap = new Heap<number>((a, b) => a > b);
  // the larger half of the window, smallest on top
  readonly minHeap = new Heap<number>((a, b) => a < b);

  rebalanceHeaps(): void {
    // either both the heaps will have equal number of elements or max-heap
    // will have one more element than the min-heap
    if (this.maxHeap.size > this.minHeap.size + 1) {
      const top = this.maxHeap.pop();
      if (top !== undefined) {
        this.minHeap.push(top);
      }
    } else if (this.maxHeap.size < this.minHeap.size) {
      const top = this.minHeap.pop();
      if (top !== undefined) {
        this.maxHeap.push(top);
      }
    }
  }
}

export function findSlidingWindowMedian(nums: number[], k: number): number[] {
  const result: number[] = [];
  const window = new Window();
  for (let i = 0; i < nums.length; i++) {
    const maxTop = window.maxHeap.peek();
    if (maxTop === undefined || maxTop >= nums[i]) {
      window.maxHeap.push(nums[i]);
    } else {
      window.minHeap.push(nums[i]);
    }
    window.rebalanceHeaps();

    // if we have at least 'k' elements in the sliding window
    if (i - k + 1 >= 0) {
      // add the median to the result
      const smallerTop = window.maxHeap.peek() ?? 0;
      if (window.maxHeap.size === window.minHeap.size) {
        // we have even number of elements, take the average of middle two
        // elements
        result.push((smallerTop + (window.minHeap.peek() ?? 0)) / 2);
      } else {
        // because max-heap will have one more element than the min-heap
        result.push(smallerTop);
      }

      // remove the element going out of the sliding window; the heap can
      // remove a number from anywhere in it, not just the top
      const elementToBeRemoved = nums[i - k + 1];
      if (elementToBeRemoved <= smallerTop) {
        window.maxHeap.remove(elementToBeRemoved);
      } else {
        window.minHeap.remove(elementToBeRemoved);
      }
      window.rebalanceHeaps();
    }
  }
  return result;
}
