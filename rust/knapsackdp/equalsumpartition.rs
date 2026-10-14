// Given a set of positive numbers,
// find if we can partition it into two subsets such that the sum of elements in
// both subsets is equal.
//
// Example 1:
// Input: {1, 2, 3, 4}
// Output: True
// Explanation: The given set can be partitioned into two subsets with equal
// sum: {1, 4} & {2, 3}
//
// Example 2:
// Input: {1, 1, 3, 4, 7}
// Output: True
// Explanation: The given set can be partitioned into two subsets with equal
// sum: {1, 3, 4} & {1, 7}
//
// Example 3:
// Input: {2, 3, 4, 6}
// Output: False
// Explanation: The given set cannot be partitioned into two subsets with equal
// sum.
// Constraints:
//
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

// bottom up dp

pub fn can_partition(nums: &[usize]) -> bool {
    let n = nums.len();
    // find the total sum
    let mut sum = 0;
    for i in 0..n {
        sum += nums[i];
    }

    // if 'sum' is an odd number, we can't have two subsets with the same total
    if sum % 2 != 0 {
        return false;
    }

    // we are trying to find a subset of given numbers that has a total sum of
    // sum/2.
    sum /= 2;

    let mut dp = vec![vec![false; sum + 1]; n];

    // populate the sum=0 columns, as we can always form '0' sum with an empty
    // set
    for i in 0..n {
        dp[i][0] = true;
    }

    // with only one number, we can form a subset only when the required sum
    // is equal to its value
    for s in 1..=sum {
        dp[0][s] = nums[0] == s;
    }

    // process all subsets for all sums
    for i in 1..n {
        for s in 1..=sum {
            if dp[i - 1][s] {
                // if we can get the sum 's' without the number at index 'i'
                dp[i][s] = dp[i - 1][s];
            } else if s >= nums[i] {
                // else we can find a subset to get the remaining sum
                dp[i][s] = dp[i - 1][s - nums[i]];
            }
        }
    }

    // the bottom-right corner will have our answer.
    dp[n - 1][sum]
}
