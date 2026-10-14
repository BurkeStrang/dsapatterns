#include <array>
#include <string>
#include <string_view>

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

bool equal_perm(std::string_view str1, std::string_view str2)
{
    std::array<int, 26> checker{};
    for (std::size_t index = 0; index < str2.size(); index++)
    {
        checker[str1[index] - 'a']++;
        checker[str2[index] - 'a']--;
    }
    for (int value : checker)
    {
        if (value != 0)
        {
            return false;
        }
    }
    return true;
}

bool find_permutation(const std::string &s, const std::string &pattern)
{
    std::string_view text = s;
    std::size_t start = 0;
    std::size_t end = pattern.size();
    while (end <= s.size())
    {
        if (equal_perm(text.substr(start, end - start), pattern))
        {
            return true;
        }
        start++;
        end++;
    }
    return false;
}
