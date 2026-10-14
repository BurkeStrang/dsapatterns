// Given an array of numbers which is sorted in ascending order and is rotated
// ‘k’ times around a pivot,
// find ‘k’.
// You can assume that the array does not have any duplicates.
// Note: You need to solve the problem in log(n) time complexity.
//
// Example 1:
// Input: [10, 15, 1, 3, 8]
// Output: 2
// Explanation: The array has been rotated 2 times.
//
// Example 2:
// Input: [4, 5, 7, 9, 10, -1, 2]
// Output: 5
// Explanation: The array has been rotated 5 times.
//
// Example 3:
// Input: [1, 3, 8, 10]
// Output: 0
// Explanation: The array has not been rotated.

pub fn count_rotations(arr: &[i32]) -> i32 {
    let mut start = 0;
    let mut end = arr.len() as i32 - 1;
    while start < end {
        let mid = start + (end - start) / 2;
        let val = arr[mid as usize];

        // if mid is greater than the next element
        if mid < end && val > arr[mid as usize + 1] {
            return mid + 1;
        }

        // if mid is smaller than the previous element
        if mid > start && arr[mid as usize - 1] > val {
            return mid;
        }

        if arr[start as usize] < val {
            // left side is sorted, so the pivot is on right side
            start = mid + 1;
        } else {
            // right side is sorted, so the pivot is on the left side
            end = mid - 1;
        }
    }

    0 // the array has not been rotated
}
