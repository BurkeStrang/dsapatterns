// We are given an unsorted array containing ‘n’ numbers taken from the range 1
// to ‘n’.
// The array originally contained all the numbers from 1 to ‘n’,
// but due to a data error,
// one of the numbers got duplicated which also resulted in one number going
// missing.
// Find both these numbers.
//
// Example 1:
// Input: [3, 1, 2, 5, 2]
// Output: [2, 4]
// Explanation: '2' is duplicated and '4' is missing.
//
// Example 2:
// Input: [3, 1, 2, 3, 6, 4]
// Output: [3, 5]
// Explanation: '3' is duplicated and '5' is missing.
// Constraints:
//
// 2 <= nums.length <=
// 1 <= nums[i] <=

/// Returns the duplicated number and the missing number.
pub fn find_corrupt(nums: &mut [i32]) -> Option<(i32, i32)> {
    let mut i = 0;
    while i < nums.len() {
        // If the current number is not in its correct position, swap it with
        // the number at its correct position.
        let j = (nums[i] - 1) as usize;
        if nums[i] != nums[j] {
            nums.swap(i, j);
        } else {
            i += 1;
        }
    }

    // Iterate through the slice to find the first misplaced number.
    for i in 0..nums.len() {
        if nums[i] != i as i32 + 1 {
            return Some((nums[i], i as i32 + 1));
        }
    }

    // No number is out of place.
    None
}
