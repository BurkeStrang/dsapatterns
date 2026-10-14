// Given a sorted array of numbers, find if a given number 'key' is present in
// the array. Though we know that the array is sorted, we don't know if it's
// sorted in ascending or descending order. You should assume that the array
// can have duplicates.
//
// Write a function to return the index of the 'key' if it is present in the
// array, otherwise return -1.

pub fn desc_or_asc_search(arr: &[i32], key: i32) -> i32 {
    let mut left = 0;
    let mut right = arr.len() as i32 - 1;
    let is_asc = arr[left as usize] < arr[right as usize];
    while left <= right {
        // calculate the middle of the current range
        let mid = left + (right - left) / 2;
        let val = arr[mid as usize];

        if key == val {
            return mid;
        }

        if is_asc {
            // ascending order
            if key < val {
                right = mid - 1; // the 'key' can be in the first half
            } else {
                left = mid + 1; // the 'key' can be in the second half
            }
        } else {
            // descending order
            if key > val {
                right = mid - 1; // the 'key' can be in the first half
            } else {
                left = mid + 1; // the 'key' can be in the second half
            }
        }
    }
    -1 // element not found
}
