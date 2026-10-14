// Given a set of numbers that might contain duplicates, find all of its
// distinct subsets.
//
// Example 1:
// Input: [1, 3, 3]
// Output: [], [1], [3], [1,3], [3,3], [1,3,3]
//
// Example 2:
// Input: [1, 5, 3, 3]
// Output: [], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3], [3,3], [1,3,3],
// [3,3,5], [1,5,3,3]

pub fn find_dup_subsets(nums: &mut [i32]) -> Vec<Vec<i32>> {
    // sort the numbers to handle duplicates
    nums.sort_unstable();
    let mut subsets = vec![vec![]];
    // the subsets added in the previous step start here
    let mut previous_step_start = 0;
    for i in 0..nums.len() {
        let mut start_index = 0;
        // if current and the previous elements are same, create new subsets
        // only from the subsets added in the previous step
        if i > 0 && nums[i] == nums[i - 1] {
            start_index = previous_step_start;
        }
        previous_step_start = subsets.len();
        for j in start_index..previous_step_start {
            // create a new subset from the existing subset and add the
            // current element to it
            let mut set = subsets[j].clone();
            set.push(nums[i]);
            subsets.push(set);
        }
    }
    subsets
}
