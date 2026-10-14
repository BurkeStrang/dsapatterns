// Given a Bitonic array, find if a given ‘key’ is present in it.
// An array is considered bitonic if it is first monotonically increasing and
// then monotonically decreasing.
// In other words,
// a bitonic array starts with a sequence of increasing elements,
// reaches a peak element,
// and then follows with a sequence of decreasing elements.
// The peak element is the maximum value in the array.
// Write a function to return the index of the ‘key’.
// If the 'key' appears more than once, return the smaller index.
// If the ‘key’ is not present, return -1.
//
// Example 1:
// Input: [1, 3, 8, 4, 3], key=4
// Output: 3
//
// Example 2:
// Input: [3, 8, 3, 1], key=8
// Output: 1
//
// Example 3:
// Input: [1, 3, 8, 12], key=12
// Output: 3
//
// Example 4:
// Input: [10, 9, 8], key=10
// Output: 0

// The searches in this pattern move 'end' to 'mid - 1', which goes to -1 when
// the key is smaller than everything, so the indices are i32 rather than
// usize and are cast where they index the array.

fn find_max(arr: &[i32]) -> i32 {
    let mut start = 0;
    let mut end = arr.len() as i32 - 1;
    while start < end {
        let mid = start + (end - start) / 2;
        if arr[mid as usize] > arr[mid as usize + 1] {
            end = mid;
        } else {
            start = mid + 1;
        }
    }

    // at the end of the while loop, 'start == end'
    start
}

// search_within is an order-agnostic binary search
fn search_within(arr: &[i32], key: i32, mut start: i32, mut end: i32) -> i32 {
    while start <= end {
        let mid = start + (end - start) / 2;
        let val = arr[mid as usize];

        if key == val {
            return mid;
        }

        if arr[start as usize] < arr[end as usize] {
            // ascending order
            if key < val {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            // descending order
            if key > val {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
    }
    -1 // element is not found
}

// search_bitonic searches for a key in a bitonic array
pub fn search_bitonic(arr: &[i32], key: i32) -> i32 {
    let max_index = find_max(arr);
    let key_index = search_within(arr, key, 0, max_index);
    if key_index != -1 {
        return key_index;
    }
    search_within(arr, key, max_index + 1, arr.len() as i32 - 1)
}
