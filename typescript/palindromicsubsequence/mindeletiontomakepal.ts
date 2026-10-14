// Given a string,
// find the minimum number of characters that we can remove to make it a
// palindrome.
//
// Example 1:
// Input: "abdbca"
// Output: 1
// Explanation: By removing "c", we get a palindrome "abdba".
//
// Example 2:
// Input: = "cddpd"
// Output: 2
// Explanation: Deleting "cp", we get a palindrome "ddd".
//
// Example 3:
// Input: = "pqr"
// Output: 2
// Explanation: We have to remove any two characters to get a palindrome, e.g.
// if we
// remove "pq", we get palindrome "r".

export function findLpsLen(st: string): number {
  const n = st.length;
  if (n === 0) {
    return 0;
  }

  // dp[i][j] stores the length of LPS from index 'i' to index 'j'
  const dp = Array.from({ length: n }, () => new Array<number>(n).fill(0));

  // every sequence with one element is a palindrome of length 1
  for (let i = 0; i < n; i++) {
    dp[i][i] = 1;
  }

  for (let startIndex = n - 1; startIndex >= 0; startIndex--) {
    for (let endIndex = startIndex + 1; endIndex < n; endIndex++) {
      if (st[startIndex] === st[endIndex]) {
        // case 1: elements at the beginning and the end are the same
        dp[startIndex][endIndex] = 2 + dp[startIndex + 1][endIndex - 1];
      } else {
        // case 2: skip one element either from the beginning or the end
        dp[startIndex][endIndex] = Math.max(
          dp[startIndex + 1][endIndex],
          dp[startIndex][endIndex - 1],
        );
      }
    }
  }

  return dp[0][n - 1];
}

export function findMinimumDeletions(st: string): number {
  // subtracting the length of Longest Palindromic Subsequence from the length
  // of the input string to get minimum number of deletions
  return st.length - findLpsLen(st);
}
