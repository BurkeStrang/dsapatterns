#include <string.h>

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

int first_uniq_char
(
    const char *str
)
{
    int str_len = (int)strlen(str);
    // create map with freq
    int freq[256] = {0};
    for (int i = 0; i < str_len; i++)
    {
        freq[(unsigned char)str[i]]++;
    }

    // loop through str to get first unique letter
    for (int index = 0; index < str_len; index++)
    {
        if (freq[(unsigned char)str[index]] == 1)
        {
            return index;
        }
    }

    return -1;
}
