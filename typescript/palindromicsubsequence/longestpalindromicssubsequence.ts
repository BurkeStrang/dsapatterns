// Given a sequence, find the length of its Longest Palindromic Subsequence
// (LPS).
// In a palindromic subsequence, elements read the same backward and forward.
// A subsequence is a sequence that can be derived from another sequence
// by deleting some or no elements without changing the order of the remaining
// elements.
//
// Example 1:
// Input: "abdbca"
// Output: 5
// Explanation: LPS is "abdba".
//
// Example 2:
// Input: = "cddpd"
// Output: 3
// Explanation: LPS is "ddd".
//
// Example 3:
// Input: = "pqr"
// Output: 1
// Explanation: LPS could be "p", "q" or "r".

export function findLpsLengthRecursive(
  st: string,
  startIndex: number,
  endIndex: number,
): number {
  if (startIndex > endIndex) {
    return 0;
  }

  // every sequence with one element is a palindrome of length 1
  if (startIndex === endIndex) {
    return 1;
  }

  // case 1: elements at the beginning and the end are the same
  if (st[startIndex] === st[endIndex]) {
    return 2 + findLpsLengthRecursive(st, startIndex + 1, endIndex - 1);
  }

  // case 2: skip one element either from the beginning or the end
  const c1 = findLpsLengthRecursive(st, startIndex + 1, endIndex);
  const c2 = findLpsLengthRecursive(st, startIndex, endIndex - 1);
  return Math.max(c1, c2);
}

export function findLpsLength(st: string): number {
  return findLpsLengthRecursive(st, 0, st.length - 1);
}
