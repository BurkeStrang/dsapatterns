// Given two arrays, find if the second one is a subarray of the first: its
// numbers appear in the first array next to each other and in the same order.

pub fn is_subarray(nums: &[i32], sub: &[i32]) -> bool {
    let n = sub.len();
    let mut i = 0;
    while i + n <= nums.len() {
        if nums[i..i + n] == *sub {
            return true;
        }
        i += 1;
    }
    false
}
