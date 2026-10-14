// Given a string, we want to cut it into pieces such that each piece is a
// palindrome.
// Write a function to return the minimum number of cuts needed.
//
// Example 1:
// Input: "abdbca"
// Output: 3
// Explanation: Palindrome pieces are "a", "bdb", "c", "a".
//
// Example 2:
// Input: = "cddpd"
// Output: 2
// Explanation: Palindrome pieces are "c", "d", "dpd".
//
// Example 3:
// Input: = "pqr"
// Output: 2
// Explanation: Palindrome pieces are "p", "q", "r".
//
// Example 4:
// Input: = "pp"
// Output: 0
// Explanation: We do not need to cut, as "pp" is a palindrome.
// Constraints:
//
// 1 <= st.length <= 16
// s contains only lowercase English letters.

export function findMppCuts(st: string): number {
  const n = st.length;
  if (n === 0) {
    return 0;
  }

  // isPalindrome[i][j] will be 'true' if the string from index 'i' to index
  // 'j' is a palindrome
  const isPalindrome = Array.from({ length: n }, () =>
    new Array<boolean>(n).fill(false),
  );

  // every string with one character is a palindrome
  for (let i = 0; i < n; i++) {
    isPalindrome[i][i] = true;
  }

  // populate isPalindrome table
  for (let startIndex = n - 1; startIndex >= 0; startIndex--) {
    for (let endIndex = startIndex + 1; endIndex < n; endIndex++) {
      // if it's a two-character string or if the remaining string is a
      // palindrome too
      if (
        st[startIndex] === st[endIndex] &&
        (endIndex - startIndex === 1 ||
          isPalindrome[startIndex + 1][endIndex - 1])
      ) {
        isPalindrome[startIndex][endIndex] = true;
      }
    }
  }

  // now let's populate the second table, every index in 'cuts' stores the
  // minimum cuts needed for the substring from that index till the end
  const cuts = new Array<number>(n).fill(0);
  for (let startIndex = n - 1; startIndex >= 0; startIndex--) {
    let minCuts = n; // maximum cuts
    for (let endIndex = n - 1; endIndex >= startIndex; endIndex--) {
      if (isPalindrome[startIndex][endIndex]) {
        // we can cut here as we got a palindrome
        // also, we don't need any cut if the whole substring is a palindrome
        if (endIndex === n - 1) {
          minCuts = 0;
        } else {
          minCuts = Math.min(minCuts, 1 + cuts[endIndex + 1]);
        }
      }
    }
    cuts[startIndex] = minCuts;
  }

  return cuts[0];
}
