use std::cmp::Ordering;

// Example 1:
// input: [4, 6, 10], key = 5
// output: 1

pub fn search_ceiling_of_a_number(arr: &[i32], key: i32) -> i32 {
    // if the 'key' is bigger than the biggest element
    if key > arr[arr.len() - 1] {
        return -1;
    }

    let mut left = 0;
    let mut right = arr.len() as i32 - 1;
    while left <= right {
        let mid = left + (right - left) / 2;
        let val = arr[mid as usize];

        // left = 0, right = 2, mid = 1, val = 6
        // right = 0
        // left = 0, right = 0, mid = 0, val = 4
        // left = 1
        // left = 1, right = 0 → exit
        // return left = 1
        match val.cmp(&key) {
            Ordering::Less => left = mid + 1,
            Ordering::Greater => right = mid - 1,
            Ordering::Equal => return mid,
        }
    }

    // since the loop is running until 'left <= right', so at the right of the
    // while loop, 'left == right+1' we are not able to find the element in the
    // given array, so the next big number will be arr[left]
    left
}
