#include <string>
#include <unordered_map>

// Given a string, identify the position of the first character that appears
// only once in the string.
// If no such character exists, return -1.
//
// Example 1:
// Input: "apple"
// Expected Output: 0
// Justification: The first character 'a' appears only once in the string and is
// the first character.
//
// Example 2:
// Input: "abcab"
// Expected Output: 2
// Justification: The first character that appears only once is 'c' and its
// position is 2.
//
// Example 3:
// Input: "abab"
// Expected Output: -1
// Justification: There is no character in the string that appears only once.
//
// Constraints:
// 1 <= s.length <= 105
// s consists of only lowercase English letters.

int first_uniq_char(const std::string &s)
{
    // create map with freq
    std::unordered_map<char, int> freq;
    for (char letter : s)
    {
        freq[letter]++;
    }

    // loop through s to get first unique letter
    for (int index = 0; index < std::ssize(s); index++)
    {
        if (freq[s[index]] == 1)
        {
            return index;
        }
    }

    return -1;
}
