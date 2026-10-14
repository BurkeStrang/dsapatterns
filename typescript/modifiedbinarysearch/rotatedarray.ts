// Given an array of numbers which is sorted in ascending order and also rotated
// by some arbitrary number,
// find if a given ‘key’ is present in it.
// Write a function to return the index of the ‘key’ in the rotated array.
// If the ‘key’ is not present, return -1. You can assume that the given array
// does not have any duplicates.
// Note: You need to solve the problem in log(n) time complexity.
//
// Example 1:
// Input: [10, 15, 1, 3, 8], key = 15
// Output: 1
// Explanation: '15' is present in the array at index '1'.
//
// Example 2:
// Input: [4, 5, 7, 9, 10, -1, 2], key = 10
// Output: 4
// Explanation: '10' is present in the array at index '4'.

export function searchRotated(arr: number[], key: number): number {
  let beg = 0;
  let end = arr.length - 1;
  while (beg <= end) {
    const mid = beg + Math.floor((end - beg) / 2);
    if (arr[mid] === key) {
      return mid;
    }

    if (arr[beg] <= arr[mid]) {
      // left side is sorted in ascending order
      if (key >= arr[beg] && key < arr[mid]) {
        end = mid - 1;
      } else {
        beg = mid + 1;
      }
    } else if (key > arr[mid] && key <= arr[end]) {
      // right side is sorted in ascending order
      beg = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return -1;
}
