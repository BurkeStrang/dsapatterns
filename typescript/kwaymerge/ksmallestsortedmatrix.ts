// Given an N * N matrix where each row and column is sorted in ascending order,
// find the Kth smallest element in the matrix.
// Example 1:
// Input: Matrix=[
//     [2, 6, 8],
//     [3, 7, 10],
//     [5, 8, 11]
//   ],
//   K=5
// Output: 7
// Explanation: The 5th smallest number in the matrix is 7.

import { Heap } from "../common/heap.ts";

// a number and where it sits in the matrix
interface Entry {
  num: number;
  row: number;
  col: number;
}

// findKthSmallestPoint finds the Kth smallest element in a matrix
export function findKthSmallestPoint(matrix: number[][], k: number): number {
  // a min heap of the entries, so the smallest number is on top
  const minHeap = new Heap<Entry>((a, b) => a.num < b.num);

  // put the 1st element of each row in the min heap
  // we don't need to push more than 'k' elements in the heap
  for (let row = 0; row < matrix.length && row < k; row++) {
    minHeap.push({ num: matrix[row][0], row, col: 0 });
  }

  // take the smallest (top) element form the min heap, if the running count
  // is equal to k return the number. if the row of the top element has more
  // elements, add the next element to the heap
  let numberCount = 0;
  let result = 0;
  for (let top = minHeap.pop(); top !== undefined; top = minHeap.pop()) {
    const { num, row } = top;
    result = num;
    numberCount++;
    if (numberCount === k) {
      break;
    }
    const col = top.col + 1;
    if (col < matrix[row].length) {
      minHeap.push({ num: matrix[row][col], row, col });
    }
  }
  return result;
}
