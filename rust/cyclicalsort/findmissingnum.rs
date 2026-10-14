// We are given an array containing n distinct numbers taken from the range 0 to
// n.
// Since the array has only n numbers out of the total n+1 numbers, find the
// missing number.
//
// Example 1:
// Input: [4, 0, 3, 1]
// Output: 2
//
// Example 2:
// Input: [8, 3, 5, 2, 4, 6, 0, 1]
// Output: 7
//
// Constraints:
// n == nums.length
// 1 <= n <=
// 0 <= nums[i] <= n
// All the numbers of nums are unique.

pub fn find_missing_number(nums: &mut [usize]) -> usize {
    let mut i = 0;
    while i < nums.len() {
        if nums[i] < nums.len() && nums[i] != nums[nums[i]] {
            nums.swap(i, nums[i]);
        } else {
            i += 1;
        }
    }

    // Find the first number missing from its index, that will be our required
    // number
    for i in 0..nums.len() {
        if nums[i] != i {
            return i;
        }
    }

    nums.len()
}
