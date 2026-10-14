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

pub fn find_permutation(s: &str, pattern: &str) -> bool {
    let s = s.as_bytes();
    let pattern = pattern.as_bytes();
    let mut start = 0;
    let mut end = pattern.len();
    while end <= s.len() {
        if equal_perm(&s[start..end], pattern) {
            return true;
        }
        start += 1;
        end += 1;
    }
    false
}

fn equal_perm(str1: &[u8], str2: &[u8]) -> bool {
    let mut checker = [0i32; 26];
    for index in 0..str2.len() {
        checker[usize::from(str1[index] - b'a')] += 1;
        checker[usize::from(str2[index] - b'a')] -= 1;
    }
    checker.iter().all(|&val| val == 0)
}
