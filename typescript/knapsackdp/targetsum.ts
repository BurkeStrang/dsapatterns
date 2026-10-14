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

// countSets is exactly similar to what we have in 'Count of Subset Sum'
// problem, solved bottom-up
export function countSets(num: number[], sum: number): number {
  const n = num.length;
  const dp = Array.from({ length: n }, () =>
    new Array<number>(sum + 1).fill(0),
  );

  // populate the sum=0 columns, as we will always have an empty set for zero
  // sum
  for (let i = 0; i < n; i++) {
    dp[i][0] = 1;
  }

  // with only one number, we can form a subset only when the required sum is
  // equal to the number
  for (let s = 1; s <= sum; s++) {
    dp[0][s] = num[0] === s ? 1 : 0;
  }

  // process all subsets for all sums
  for (let i = 1; i < n; i++) {
    for (let s = 1; s <= sum; s++) {
      dp[i][s] = dp[i - 1][s];
      if (s >= num[i]) {
        dp[i][s] += dp[i - 1][s - num[i]];
      }
    }
  }

  // the bottom-right corner will have our answer.
  return dp[n - 1][sum];
}

export function findTargetSubsets(num: number[], s: number): number {
  let totalSum = 0;
  for (const n of num) {
    totalSum += n;
  }

  // if 's + totalSum' is odd, we can't find a subset with sum equal to
  // '(s + totalSum) / 2'
  if (totalSum < s || (s + totalSum) % 2 === 1) {
    return 0;
  }

  return countSets(num, (s + totalSum) / 2);
}
