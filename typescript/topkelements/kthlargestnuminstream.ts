// Design a class to efficiently find the Kth largest element in a stream of
// numbers.
// The class should have the following two things:
// The constructor of the class should accept an integer array containing
// initial numbers from the stream and an integer ‘K’.
// The class should expose a function add(int num) which will store the given
// number and return the Kth largest number.
//
// Example 1:
// Input: [3, 1, 5, 12, 2, 11], K = 4
// 1. Calling add(6) should return '5'.
// 2. Calling add(13) should return '6'.
// 2. Calling add(4) should still return '6'.

import { Heap } from "../common/heap.ts";

export class KthLargest {
  // a min heap holding the 'k' largest numbers seen so far
  private readonly minHeap = new Heap<number>((a, b) => a < b);
  private readonly k: number; // The value of 'k'

  constructor(nums: number[], k: number) {
    this.k = k;
    for (const num of nums) {
      this.add(num);
    }
  }

  add(num: number): number {
    this.minHeap.push(num);
    if (this.minHeap.size > this.k) {
      this.minHeap.pop();
    }
    return this.minHeap.peek() ?? num;
  }
}
