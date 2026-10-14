// Design a class to calculate the median of a number stream. The class should
// have the following two methods:
//
// insert_num(num): stores the number in the class
// find_median(): returns the median of all numbers inserted in the class
//
// If the count of numbers inserted in the class is even, the median will be
// the average of the middle two numbers.

import { Heap } from "../common/heap.ts";

export class Median {
  // the smaller half of the numbers, largest on top
  private readonly maxHeap = new Heap<number>((a, b) => a > b);
  // the larger half of the numbers, smallest on top
  private readonly minHeap = new Heap<number>((a, b) => a < b);

  insertNum(num: number): void {
    const maxTop = this.maxHeap.peek();
    if (maxTop === undefined || maxTop >= num) {
      this.maxHeap.push(num);
    } else {
      this.minHeap.push(num);
    }

    // either both the heaps will have equal number of elements or max-heap
    // will have one more element than the min-heap
    if (this.maxHeap.size > this.minHeap.size + 1) {
      moveTop(this.maxHeap, this.minHeap);
    } else if (this.maxHeap.size < this.minHeap.size) {
      moveTop(this.minHeap, this.maxHeap);
    }
  }

  findMedian(): number {
    const maxTop = this.maxHeap.peek() ?? 0;
    if (this.maxHeap.size === this.minHeap.size) {
      // we have even number of elements, take the average of middle two
      // elements
      return maxTop / 2 + (this.minHeap.peek() ?? 0) / 2;
    }

    // because max-heap will have one more element than the min-heap
    return maxTop;
  }
}

// moveTop moves the top number of one heap onto the other.
function moveTop(from: Heap<number>, to: Heap<number>): void {
  const top = from.pop();
  if (top !== undefined) {
    to.push(top);
  }
}
