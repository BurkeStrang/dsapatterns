#include <stdbool.h>
#include <string.h>

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

// equal_perm reports whether the first len characters of str1 and str2 are a
// permutation of each other.
bool equal_perm
(
    const char *str1,
    const char *str2,
    int len
)
{
    int checker[26] = {0};
    for (int index = 0; index < len; index++)
    {
        checker[str1[index] - 'a']++;
        checker[str2[index] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (checker[i] != 0)
        {
            return false;
        }
    }
    return true;
}

bool find_permutation
(
    const char *str,
    const char *pattern
)
{
    int str_len = (int)strlen(str);
    int win_len = (int)strlen(pattern);
    int start = 0;
    int end = win_len - 1;
    while (end < str_len)
    {
        if (equal_perm(str + start, pattern, win_len))
        {
            return true;
        }
        start++;
        end++;
    }
    return false;
}
