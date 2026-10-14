use std::cmp::Ordering;

// Given an array of numbers sorted in ascending order,
// find the element in the array that has the minimum difference with the given
// ‘key’.
//
// Example 1:
// Input: [4, 6, 10], key = 7
// Output: 6
// Explanation: The difference between the key '7' and '6' is minimum than any
// other number in the array
//
// Example 2:
// Input: [4, 6, 10], key = 4
// Output: 4
//
// Example 3:
// Input: [1, 3, 8, 10, 15], key = 12
// Output: 10
//
// Example 4:
// Input: [4, 6, 10], key = 17
// Output: 10

pub fn search_min_diff(arr: &[i32], key: i32) -> i32 {
    // smaller than the smallest element
    if key < arr[0] {
        return arr[0];
    }

    // larger than the largest element
    if key > arr[arr.len() - 1] {
        return arr[arr.len() - 1];
    }

    let mut start = 0;
    let mut end = arr.len() as i32 - 1;
    while start <= end {
        let mid = start + (end - start) / 2;
        let val = arr[mid as usize];
        match key.cmp(&val) {
            Ordering::Less => end = mid - 1,
            Ordering::Greater => start = mid + 1,
            Ordering::Equal => return val,
        }
    }

    // at the end of the while loop, 'start == end+1'
    // we are not able to find the element in the given array
    // return the element which is closest to the 'key'
    let (after, before) = (arr[start as usize], arr[end as usize]);
    if (after - key) < (key - before) {
        return after;
    }
    before
}
