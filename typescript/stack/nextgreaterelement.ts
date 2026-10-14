// Given an array, print the Next Greater Element (NGE) for every element.
//
// The Next Greater Element for an element x is the first greater element on the
// right side of x in the array.
//
// Elements for which no greater element exist, consider the next greater
// element as -1.
//
// Examples
// Example 1:
//
//  Input: [4, 5, 2, 25]
//  Output: [5, 25, 25, -1]
//  Explanation: The NGE for 4 is 5, 5 is 25, 2 is 25, and there is no NGE for
//  25.
// Example 1:
//
//  Input: [13, 7, 6, 12]
//  Output: [-1, 12, 12, -1]
// Example 1:
//
//  Input: [1, 2, 3, 4, 5]
//  Output: [2, 3, 4, 5, -1]
// Constraints:
//
// 1 <= arr.length <= 104
// -10^9 <= arr[i] <= 10^9

export function nextLargerElement(arr: number[]): number[] {
  const n = arr.length;
  const s: number[] = []; // An array serves as the stack.
  const res = new Array<number>(n).fill(0); // A list to store the results.

  // Iterate through the input array in reverse order.
  for (let i = n - 1; i >= 0; i--) {
    // Remove elements from the stack while they are less than or equal to
    // the current element.
    let top = s.at(-1);
    while (top !== undefined && top <= arr[i]) {
      s.pop();
      top = s.at(-1);
    }

    // If the stack is empty, there is no greater element to the right.
    // Otherwise, the greater element is the top element of the stack.
    res[i] = top ?? -1;

    // Push the current element onto the stack.
    s.push(arr[i]);
  }

  return res;
}
