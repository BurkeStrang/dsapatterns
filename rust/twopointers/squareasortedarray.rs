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

pub fn make_squares(arr: &[i32]) -> Vec<i32> {
    let n = arr.len();
    let mut squares = vec![0; n];
    // The next free position in the output, filled from the highest down.
    let mut highest_square_idx = n;
    // Two pointers for the input array; 'right' is one past the right element.
    let mut left = 0;
    let mut right = n;

    // Traverse the input array from both ends towards the center.
    while left < right {
        let left_square = arr[left] * arr[left];
        let right_square = arr[right - 1] * arr[right - 1];
        highest_square_idx -= 1;

        // Compare the squared values and store the larger one in the output.
        if left_square > right_square {
            squares[highest_square_idx] = left_square;
            left += 1; // Move the left pointer to the right.
        } else {
            squares[highest_square_idx] = right_square;
            right -= 1; // Move the right pointer to the left.
        }
    }

    squares
}
