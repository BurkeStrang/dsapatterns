// Given a string, find the total number of palindromic substrings in it.
// Please note we need to find the total number of substrings and not
// subsequences.
//
// Example 1:
// Input: "abdbca"
// Output: 7
// Explanation: Here are the palindromic substrings, "a", "b", "d", "b", "c",
// "a", "bdb".
//
// Example 2:
// Input: = "cddpd"
// Output: 7
// Explanation: Here are the palindromic substrings, "c", "d", "d", "p", "d",
// "dd", "dpd".
//
// Example 3:
// Input: = "pqr"
// Output: 3
// Explanation: Here are the palindromic substrings,"p", "q", "r".

export function findCps(st: string): number {
  const n = st.length;
  // dp[i][j] will be 'true' if the string from index 'i' to index 'j' is a
  // palindrome
  const dp = Array.from({ length: n }, () => new Array<boolean>(n).fill(false));
  let count = 0;

  // every string with one character is a palindrome
  for (let i = 0; i < n; i++) {
    dp[i][i] = true;
    count++;
  }

  // abdbca
  // dp is now 6 by 6:
  //         [true,false,false,false,false,false],
  //         [false,true,false,false,false,false],
  //         [false,false,true,false,false,false],
  //         [false,false,false,true,false,false],
  //         [false,false,false,false,true,false],
  //         [false,false,false,false,false,true],

  for (let startIndex = n - 1; startIndex >= 0; startIndex--) {
    for (let endIndex = startIndex + 1; endIndex < n; endIndex++) {
      // if it's a two-character string or if the remaining string is a
      // palindrome too
      if (
        st[startIndex] === st[endIndex] &&
        (endIndex - startIndex === 1 || dp[startIndex + 1][endIndex - 1])
      ) {
        dp[startIndex][endIndex] = true;
        count++;
      }
    }
  }

  return count;
}
