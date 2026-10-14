use std::cmp::Ordering;

// Given an infinite sorted array (or an array with unknown size),
// find if a given number ‘key’ is present in the array.
// Write a function to return the index of the ‘key’ if it is present in the
// array, otherwise return -1.
// Since it is not possible to define an array with infinite (unknown) size,
// you will be provided with an interface ArrayReader to read elements of the
// array.
// ArrayReader.get(index) will return the number at index;
// if the array’s size is smaller than the index, it will return
// Integer.MAX_VALUE.
//
// Example 1:
// Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 16
// Output: 6
// Explanation: The key is present at index '6' in the array.
//
// Example 2:
// Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 11
// Output: -1
// Explanation: The key is not present in the array.
//
// Example 3:
// Input: [1, 3, 8, 10, 15], key = 15
// Output: 4
// Explanation: The key is present at index '4' in the array.
//
// Example 4:
// Input: [1, 3, 8, 10, 15], key = 200
// Output: -1
// Explanation: The key is not present in the array.

pub struct ArrayReader {
    pub arr: Vec<i32>,
}

impl ArrayReader {
    pub fn get(&self, index: i32) -> i32 {
        match self.arr.get(index as usize) {
            Some(&val) => val,
            None => i32::MAX,
        }
    }
}

pub fn search_infinite_sorted_array(reader: &ArrayReader, key: i32) -> i32 {
    // find the proper bounds first
    let mut start = 0;
    let mut end = 1;
    while reader.get(end) < key {
        let new_start = end + 1;
        end += (end - start + 1) * 2; // increase to double the bounds size
        start = new_start;
    }
    binary_search(reader, key, start, end)
}

fn binary_search(
    reader: &ArrayReader,
    key: i32,
    mut start: i32,
    mut end: i32,
) -> i32 {
    while start <= end {
        let mid = start + (end - start) / 2;
        match key.cmp(&reader.get(mid)) {
            Ordering::Less => end = mid - 1,
            Ordering::Greater => start = mid + 1,
            Ordering::Equal => return mid, // found the key
        }
    }
    -1
}
