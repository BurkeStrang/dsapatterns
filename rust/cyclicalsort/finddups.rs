// We are given an unsorted array containing n numbers taken from the range 1 to
// n.
// The array has some numbers appearing twice,
// find all these duplicate numbers using constant space.
//
// Example 1:
// Input: [3, 4, 4, 5, 5]
// Output: [4, 5]
//
// Example 2:
// Input: [5, 4, 7, 2, 3, 5, 3]
// Output: [3, 5]
// Constraints:
//
// nums.length == n
// 1 <= n <=
// 1 <= nums[i] <= n
// Each element in nums appears once or twice.

pub fn find_dups(nums: &mut [i32]) -> Vec<i32> {
    let mut i = 0;
    while i < nums.len() {
        let j = (nums[i] - 1) as usize;
        if nums[i] != nums[j] {
            // The current element is not in its correct position: swap it with
            // the element at its correct position.
            nums.swap(i, j);
        } else {
            // Move to the next element if the current element is already in
            // its correct position.
            i += 1;
        }
    }

    let mut duplicate_numbers = Vec::new();
    for i in 0..nums.len() {
        // Elements that are not in their correct positions are duplicates.
        if nums[i] != i as i32 + 1 {
            duplicate_numbers.push(nums[i]);
        }
    }

    duplicate_numbers
}
