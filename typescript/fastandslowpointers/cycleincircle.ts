// We are given an array containing positive and negative numbers. Suppose the
// array contains a number ‘M’ at a particular index.
// Now, if ‘M’ is positive we will move forward ‘M’ indices and if ‘M’ is
// negative move backwards ‘M’ indices.
// You should assume that the array is circular which means two things:
//
// If, while moving forward, we reach the end of the array, we will jump to the
// first element to continue the movement.
// If, while moving backward, we reach the beginning of the array, we will jump
// to the last element to continue the movement.
// Write a method to determine if the array has a cycle.
// The cycle should have more than one element and should follow one direction
// which means the cycle should not contain both forward and backward movements.
//
// Example 1:
//
// Input: [1, 2, -1, 2, 2]
// Output: true
// Explanation: The array has a cycle among indices: 0 -> 1 -> 3 -> 0
// Example 2:
//
// Input: [2, 2, -1, 2]
// Output: true
// Explanation: The array has a cycle among indices: 1 -> 3 -> 1
// Example 3:
//
// Input: [2, 1, -1, -2]
// Output: false
// Explanation: The array does not have any cycle.
// Constraints:
//
// 1 <= nums.length <= 5000
// `-1000 <= nums[i] <= 1000
// nums[i] != 0

// findNextIndex returns the index the number at currentIndex jumps to, or -1
// if the jump changes direction or lands where it started
export function findNextIndex(
  arr: number[],
  isForward: boolean,
  currentIndex: number,
): number {
  const direction = arr[currentIndex] >= 0;
  if (isForward !== direction) {
    return -1; // change in direction, return -1
  }

  const n = arr.length;
  let nextIndex = (currentIndex + arr[currentIndex]) % n;
  if (nextIndex < 0) {
    nextIndex += n; // wrap around for negative numbers
  }

  // one element cycle, return -1
  if (nextIndex === currentIndex) {
    nextIndex = -1;
  }
  return nextIndex;
}

export function loopExists(arr: number[]): boolean {
  for (let i = 0; i < arr.length; i++) {
    const isForward = arr[i] >= 0; // if we are moving forward or not
    let slow = i;
    let fast = i;

    // if slow or fast becomes '-1' this means we can't find cycle for this
    // number
    for (;;) {
      // move one step for slow pointer
      slow = findNextIndex(arr, isForward, slow);
      // move one step for fast pointer
      fast = findNextIndex(arr, isForward, fast);
      if (fast !== -1) {
        // move another step for fast pointer
        fast = findNextIndex(arr, isForward, fast);
      }
      if (slow === -1 || fast === -1 || slow === fast) {
        break;
      }
    }

    if (slow !== -1 && slow === fast) {
      return true;
    }
  }
  return false;
}
