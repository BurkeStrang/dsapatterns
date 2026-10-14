// Given a string and a pattern, find out if the string contains any permutation
// of the pattern.
//
// Permutation is defined as the re-arranging of the characters of the string.
// For example, “abc” has the following six permutations:
//
// abc
// acb
// bac
// bca
// cab
// cba
// If a string has ‘n’ distinct characters, it will have n! permutations.
//
// Example 1:
// Input: str="oidbcaf", pattern="abc"
// Output: true
// Explanation: The string contains "bca" which is a permutation of the given
// pattern.
//
// Example 2:
// Input: str="odicf", pattern="dc"
// Output: false
// Explanation: No permutation of the pattern is present in the given string as
// a substring.
//
// Example 3:
// Input: str="bcdxabcdy", pattern="bcdyabcdx"
// Output: true
// Explanation: Both the string and the pattern are a permutation of each other.
//
// Example 4:
// Input: str="aaacb", pattern="abc"
// Output: true
// Explanation: The string contains "acb" which is a permutation of the given
// pattern.
// Constraints:
//
// 1 <= str.length, pat.length <= 104
// str and pat consist of lowercase English letters.

export function equalPerm(str1: string, str2: string): boolean {
  const checker = new Array<number>(26).fill(0);
  const a = "a".charCodeAt(0);
  for (let index = 0; index < str2.length; index++) {
    checker[str1.charCodeAt(index) - a]++;
    checker[str2.charCodeAt(index) - a]--;
  }
  return checker.every((value) => value === 0);
}

export function findPermutation(s: string, pattern: string): boolean {
  let start = 0;
  let end = pattern.length;
  while (end <= s.length) {
    if (equalPerm(s.slice(start, end), pattern)) {
      return true;
    }
    start++;
    end++;
  }
  return false;
}
