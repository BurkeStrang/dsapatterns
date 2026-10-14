// Problem Statement
// Given a sorted array, create a new array containing squares of all the
// numbers of the input array in the sorted order.
//
// Example 1:
//
// Input: [-2, -1, 0, 2, 3]
// Output: [0, 1, 4, 4, 9]
// Example 2:
//
// Input: [-3, -1, 0, 1, 2]
// Output: [0, 1, 1, 4, 9]
// Constraints:
//
// 1 <= arr.length <= 104
// -104 <= arr[i] <= 104
// arr is sorted in non-decreasing order.

export function makeSquares(arr: number[]): number[] {
  const n = arr.length;
  const squares = new Array<number>(n).fill(0);
  // The next free position in the output, filled from the highest down.
  let highestSquareIdx = n - 1;
  // Two pointers for the input array.
  let left = 0;
  let right = n - 1;

  // Traverse the input array from both ends towards the center.
  while (left <= right) {
    const leftSquare = arr[left] * arr[left];
    const rightSquare = arr[right] * arr[right];

    // Compare the squared values and store the larger one in the output.
    if (leftSquare > rightSquare) {
      squares[highestSquareIdx] = leftSquare;
      left++; // Move the left pointer to the right.
    } else {
      squares[highestSquareIdx] = rightSquare;
      right--; // Move the right pointer to the left.
    }
    highestSquareIdx--;
  }

  return squares;
}
