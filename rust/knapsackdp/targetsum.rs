// You are given a set of positive numbers and a target sum ‘S’.
// Each number should be assigned either a ‘+’ or ‘-’ sign.
// We need to find the total ways to assign symbols to make the sum of the
// numbers equal to the target ‘S’.
//
// Example 1:
// Input: {1, 1, 2, 3}, S=1
// Output: 3
// Explanation: The given set has '3' ways to make a sum of '1': {+1-1-2+3} &
// {-1+1-2+3} & {+1+1+2-3}
//
// Example 2:
// Input: {1, 2, 7, 1}, S=9
// Output: 2
// Explanation: The given set has '2' ways to make a sum of '9': {+1+2+7-1} &
// {-1+2+7+1}

pub fn find_target_subsets(num: &[usize], s: usize) -> usize {
    let mut total_sum = 0;
    for &n in num {
        total_sum += n;
    }

    // if 's + total_sum' is odd, we can't find a subset with sum equal to
    // '(s + total_sum) / 2'
    if total_sum < s || (s + total_sum) % 2 == 1 {
        return 0;
    }

    count_sets(num, (s + total_sum) / 2)
}

// this function is exactly similar to what we have in 'Count of Subset Sum'
// problem, solved bottom-up
fn count_sets(num: &[usize], sum: usize) -> usize {
    let n = num.len();
    let mut dp = vec![vec![0; sum + 1]; n];

    // populate the sum=0 columns, as we will always have an empty set for
    // zero sum
    for i in 0..n {
        dp[i][0] = 1;
    }

    // with only one number, we can form a subset only when the required sum
    // is equal to the number
    for s in 1..=sum {
        dp[0][s] = if num[0] == s { 1 } else { 0 };
    }

    // process all subsets for all sums
    for i in 1..n {
        for s in 1..=sum {
            dp[i][s] = dp[i - 1][s];
            if s >= num[i] {
                dp[i][s] += dp[i - 1][s - num[i]];
            }
        }
    }

    // the bottom-right corner will have our answer.
    dp[n - 1][sum]
}
