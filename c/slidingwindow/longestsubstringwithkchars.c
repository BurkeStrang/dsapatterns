#include <string.h>

// Given a string, find the length of the longest substring in it with no more
// than K distinct characters.
// You can assume that K is less than or equal to the length of the given
// string.
//
// Example 1:
// Input: String="araaci", K=2
// Output: 4
// Explanation: The longest substring with no more than '2' distinct characters
// is "araa".
//
// Example 2:
// Input: String="araaci", K=1
// Output: 2
// Explanation: The longest substring with no more than '1' distinct characters
// is "aa".
//
// Example 3:
// Input: String="cbbebi", K=3
// Output: 5
// Explanation: The longest substrings with no more than '3' distinct characters
// are "cbbeb" & "bbebi".
// Constraints:
//
// 1 <= str.length <= 5 * 104
// 0 <= K <= 50

int find_length
(
    const char *str,
    int k
)
{
    int str_len = (int)strlen(str);
    int window_start = 0;
    int max_length = 0;
    // how many of each character are in the window, and how many distinct
    // characters that is
    int char_frequency[256] = {0};
    int distinct = 0;
    // in the following loop we'll try to extend the range
    // [window_start, window_end]
    for (int window_end = 0; window_end < str_len; window_end++)
    {
        unsigned char right_char = (unsigned char)str[window_end];
        if (char_frequency[right_char] == 0)
        {
            distinct++;
        }
        char_frequency[right_char]++;
        // shrink the sliding window, until we are left with 'k' distinct
        // characters in the frequency map
        while (distinct > k)
        {
            unsigned char left_char = (unsigned char)str[window_start];
            char_frequency[left_char]--;
            if (char_frequency[left_char] == 0)
            {
                distinct--;
            }
            window_start++; // shrink the window
        }
        // remember the maximum length so far
        if (window_end - window_start + 1 > max_length)
        {
            max_length = window_end - window_start + 1;
        }
    }
    return max_length;
}
