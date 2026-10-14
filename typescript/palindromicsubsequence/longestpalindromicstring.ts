// Given a string, find the length of its Longest Palindromic Substring (LPS).
// In a palindromic string, elements read the same backward and forward.
//
// Example 1:
// Input: "abdbca"
// Output: 3
// Explanation: LPS is "bdb".
//
// Example 2:
// Input: = "cddpd"
// Output: 3
// Explanation: LPS is "dpd".
//
// Example 3:
// Input: = "pqr"
// Output: 1
// Explanation: LPS could be "p", "q" or "r".

export function palindromeLength(
  st: string,
  startIndex: number,
  endIndex: number,
): number {
  if (startIndex > endIndex) {
    return 0;
  }

  // every string with one character is a palindrome
  if (startIndex === endIndex) {
    return 1;
  }

  // case 1: elements at the beginning and the end are the same
  if (st[startIndex] === st[endIndex]) {
    const remainingLength = endIndex - startIndex - 1;
    // check if the remaining string is also a palindrome
    if (
      remainingLength === palindromeLength(st, startIndex + 1, endIndex - 1)
    ) {
      return remainingLength + 2;
    }
  }

  // case 2: skip one character either from the beginning or the end
  const c1 = palindromeLength(st, startIndex + 1, endIndex);
  const c2 = palindromeLength(st, startIndex, endIndex - 1);
  return Math.max(c1, c2);
}

export function findLpStringLength(st: string): number {
  return palindromeLength(st, 0, st.length - 1);
}
