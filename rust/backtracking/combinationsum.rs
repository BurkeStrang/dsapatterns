// Given an array of distinct positive integers candidates and a target integer
// target,
// return a list of all unique combinations of candidates where the chosen
// numbers sum to target.
// You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times.
// Two combinations are unique if the frequency of at least one of the chosen
// numbers is different.
//
// Example 1:
// Input: candidates = [2, 3, 6, 7], target = 7
// Output: [[2, 2, 3], [7]]
// Explanation: The elements in these two combinations sum up to 7.
//
// Example 2:
// Input: candidates = [2, 4, 6, 8], target = 10
// Output: [[2,2,2,2,2], [2,2,2,4], [2,2,6], [2,4,4], [2,8], [4,6]]
// Explanation: The elements in these six combinations sum up to 10.
// Constraints:
//
// 1 <= candidates.length <= 30
// 2 <= candidates[i] <= 40
// All elements of candidates are distinct.
// 1 <= target <= 40

pub fn combination_sum(candidates: &[i32], target: i32) -> Vec<Vec<i32>> {
    let mut res = Vec::new();
    backtrack(candidates, 0, target, &mut Vec::new(), &mut res);
    res
}

fn backtrack(
    candidates: &[i32],
    start: usize,
    target: i32,
    comb: &mut Vec<i32>,
    res: &mut Vec<Vec<i32>>,
) {
    if target == 0 {
        res.push(comb.clone());
        return;
    }

    for i in start..candidates.len() {
        if target < candidates[i] {
            continue;
        }
        comb.push(candidates[i]);
        backtrack(candidates, i, target - candidates[i], comb, res);
        comb.pop();
    }
}
