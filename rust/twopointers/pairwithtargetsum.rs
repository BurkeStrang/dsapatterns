use std::cmp::Ordering;

// Given a sorted array and a target sum, find the indices of a pair of
// numbers that add up to the target. Returns None if there is no such pair.

pub fn search(arr: &[i32], target_sum: i32) -> Option<(usize, usize)> {
    if arr.is_empty() {
        return None;
    }
    let mut left = 0;
    let mut right = arr.len() - 1;
    while left < right {
        let sum = arr[left] + arr[right];
        match sum.cmp(&target_sum) {
            Ordering::Equal => return Some((left, right)),
            Ordering::Less => left += 1,
            Ordering::Greater => right -= 1,
        }
    }
    None
}
