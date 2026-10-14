#include <string>

// Given two strings containing backspaces (identified by the character ‘#’),
// check if the two strings are equal.
//
// Example 1:
//
// Input: str1="xy#z", str2="xzz#"
// Output: true
// Explanation: After applying backspaces the strings become "xz" and "xz"
// respectively.
// Example 2:
//
// Input: str1="xy#z", str2="xyz#"
// Output: false
// Explanation: After applying backspaces the strings become "xz" and "xy"
// respectively.
// Example 3:
//
// Input: str1="xp#", str2="xyz##"
// Output: true
// Explanation: After applying backspaces the strings become "x" and "x"
// respectively.
// In "xyz##", the first '#' removes the character 'z' and the second '#'
// removes the character 'y'.
// Example 4:
//
// Input: str1="xywrrmp", str2="xywrrmu#p"
// Output: true
// Explanation: After applying backspaces the strings become "xywrrmp" and
// "xywrrmp" respectively.
// Constraints:
//
// 1 <= str1.length, str2.length <= 200
// str1 and str2 only contain lowercase letters and '#' characters.

// get_next_valid_char_index returns the index of the next character that is
// not deleted by a backspace, looking from index towards the start; -1 once
// we have gone past the start
int get_next_valid_char_index(const std::string &s, int index)
{
    int backspace_count = 0;
    while (index >= 0)
    {
        if (s[index] == '#')
        {
            // found a backspace character
            backspace_count++;
        }
        else if (backspace_count > 0)
        {
            // a non-backspace character
            backspace_count--;
        }
        else
        {
            break;
        }
        index--; // skip a backspace or a valid character
    }
    return index;
}

bool compare(const std::string &str1, const std::string &str2)
{
    // the next character to look at in each string, counting from the end
    int index1 = std::ssize(str1) - 1;
    int index2 = std::ssize(str2) - 1;
    while (index1 >= 0 || index2 >= 0)
    {
        int i1 = get_next_valid_char_index(str1, index1);
        int i2 = get_next_valid_char_index(str2, index2);
        if (i1 < 0 && i2 < 0)
        {
            return true; // reached the end of both the strings
        }
        if (i1 < 0 || i2 < 0)
        {
            return false; // reached the end of one of the strings
        }
        if (str1[i1] != str2[i2])
        {
            return false; // check if the characters are equal
        }
        index1 = i1 - 1;
        index2 = i2 - 1;
    }
    return true;
}
