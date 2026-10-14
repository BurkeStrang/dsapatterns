// Given an unsorted array containing numbers, find the smallest missing
// positive number in it.
//
// Note: Positive numbers start from '1'.
//
// Example 1:
//
// Input: [-3, 1, 5, 4, 2]
// Output: 3
// Explanation: The smallest missing positive number is '3'
// Example 2:
//
// Input: [3, -2, 0, 1, 2]
// Output: 4
// Example 3:
//
// Input: [3, 2, 5, 1]
// Output: 4
// Example 4:
//
// Input: [33, 37, 5]
// Output: 1
// Constraints:
//
// 1 <= nums.length <=
// -231 <= nums[i] <= 231 - 1

pub fn find_mis(nums: &mut [i32]) -> i32 {
    let n = nums.len() as i32;
    let mut i = 0;

    // Rearrange the elements to place each positive integer at its correct
    // index. Negative numbers and numbers greater than the array size are
    // ignored.
    while i < nums.len() {
        if nums[i] > 0
            && nums[i] <= n
            && nums[i] != nums[(nums[i] - 1) as usize]
        {
            nums.swap(i, (nums[i] - 1) as usize);
        } else {
            i += 1;
        }
    }

    // Find the first index where the element does not match its expected
    // positive value.
    for i in 0..nums.len() {
        if nums[i] != i as i32 + 1 {
            return i as i32 + 1;
        }
    }

    // If all elements from 1 to nums.len() are present, return nums.len() + 1.
    n + 1
}
