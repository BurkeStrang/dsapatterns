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

pub fn search_rotated(arr: &[i32], key: i32) -> i32 {
    let mut beg = 0;
    let mut end = arr.len() as i32 - 1;
    while beg <= end {
        let mid = beg + (end - beg) / 2;
        let val = arr[mid as usize];
        if val == key {
            return mid;
        }

        if arr[beg as usize] <= val {
            // left side is sorted in ascending order
            if key >= arr[beg as usize] && key < val {
                end = mid - 1;
            } else {
                beg = mid + 1;
            }
        } else {
            // right side is sorted in ascending order
            if key > val && key <= arr[end as usize] {
                beg = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }
    -1
}
