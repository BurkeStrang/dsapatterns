use std::cmp::Ordering;

// Given an array of numbers sorted in ascending order, find the range of a
// given number ‘key’.
// The range of the ‘key’ will be the first and last position of the ‘key’ in
// the array.
// Write a function to return the range of the ‘key’. If the ‘key’ is not
// present return [-1, -1].
//
// Example 1:
// Input: [4, 6, 6, 6, 9], key = 6
// Output: [1, 3]
//
// Example 2:
// Input: [1, 3, 8, 10, 15], key = 10
// Output: [3, 3]
//
// Example 3:
// Input: [1, 3, 8, 10, 15], key = 12
// Output: [-1, -1]

pub fn find_range(arr: &[i32], key: i32) -> [i32; 2] {
    let mut result = [-1, -1];
    result[0] = search(arr, key, false);
    // no need to search, if 'key' is not present in the input array
    if result[0] != -1 {
        result[1] = search(arr, key, true);
    }
    result
}

fn search(arr: &[i32], key: i32, find_max_index: bool) -> i32 {
    let mut key_index = -1;
    let mut start = 0;
    let mut end = arr.len() as i32 - 1;
    while start <= end {
        let mid = start + (end - start) / 2;
        match key.cmp(&arr[mid as usize]) {
            Ordering::Less => end = mid - 1,
            Ordering::Greater => start = mid + 1,
            Ordering::Equal => {
                key_index = mid;
                if find_max_index {
                    // search ahead to find the last index of 'key'
                    start = mid + 1;
                } else {
                    // search behind to find the first index of 'key'
                    end = mid - 1;
                }
            }
        }
    }
    key_index
}
