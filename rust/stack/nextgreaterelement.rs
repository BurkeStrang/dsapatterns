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

pub fn next_larger_element(arr: &[i32]) -> Vec<i32> {
    let n = arr.len();
    let mut s: Vec<i32> = Vec::new(); // A Vec serves as the stack.
    let mut res = vec![0; n]; // A list to store the results.

    // Iterate through the input array in reverse order.
    for i in (0..n).rev() {
        // Remove elements from the stack while they are less than or equal to
        // the current element.
        while s.last().is_some_and(|&top| top <= arr[i]) {
            s.pop();
        }

        // If the stack is empty, there is no greater element to the right.
        // Otherwise, the greater element is the top element of the stack.
        res[i] = s.last().copied().unwrap_or(-1);

        // Push the current element onto the stack.
        s.push(arr[i]);
    }

    res
}
