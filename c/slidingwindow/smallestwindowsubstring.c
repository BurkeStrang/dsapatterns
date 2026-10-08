#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Given a string and a pattern, find the smallest substring in the given string
// which has all the character occurrences of the given pattern.
//
// Example 1:
// Input: String="aabdec", Pattern="abc"
// Output: "abdec"
// Explanation: The smallest substring having all characters of the pattern is
// "abdec"
//
// Example 2:
// Input: String="aabdec", Pattern="abac"
// Output: "aabdec"
// Explanation: The smallest substring having all characters occurrences of the
// pattern is "aabdec"
//
// Example 3:
// Input: String="abdbca", Pattern="abc"
// Output: "bca"
// Explanation: The smallest substring having all characters of the pattern is
// "bca".
//
// Example 4:
// Input: String="adcad", Pattern="abc"
// Output: ""
// Explanation: No substring in the given string has all characters of the
// pattern
// Constraints:
//
// m == String.length
// n == Pattern.length
// 1 <= m, n <= 105
// String and Pattern consist of uppercase and lowercase English letters.

// The substring is returned as a new string that the caller must free.
char *find_substring
(
    const char *str,
    const char *pattern
)
{
    int str_len = (int)strlen(str);
    int pattern_len = (int)strlen(pattern);
    int window_start = 0;
    int matched = 0;
    int min_length = str_len + 1;
    int sub_str_start = 0;
    // how many of each pattern character we still need, and which characters
    // are part of the pattern at all
    int char_frequency[256] = {0};
    bool in_pattern[256] = {false};

    for (int i = 0; i < pattern_len; i++)
    {
        unsigned char chr = (unsigned char)pattern[i];
        char_frequency[chr]++;
        in_pattern[chr] = true;
    }

    // try to extend the range [window_start, window_end]
    for (int window_end = 0; window_end < str_len; window_end++)
    {
        unsigned char right_char = (unsigned char)str[window_end];
        if (in_pattern[right_char])
        {
            char_frequency[right_char]--;
            if (char_frequency[right_char] >= 0)
            {
                matched++;
            }
        }

        // shrink the window if we can, finish as soon as we remove a matched
        // character
        while (matched == pattern_len)
        {
            if (min_length > window_end - window_start + 1)
            {
                min_length = window_end - window_start + 1;
                sub_str_start = window_start;
            }

            unsigned char left_char = (unsigned char)str[window_start];
            window_start++;
            if (in_pattern[left_char])
            {
                // note that we could have redundant matching characters,
                // therefore we'll decrement the matched count only when a
                // useful occurrence of a matched character is going out of
                // the window
                if (char_frequency[left_char] == 0)
                {
                    matched--;
                }
                char_frequency[left_char]++;
            }
        }
    }

    if (min_length > str_len)
    {
        min_length = 0;
    }
    char *result = malloc((size_t)min_length + 1);
    memcpy(result, str + sub_str_start, (size_t)min_length);
    result[min_length] = '\0';
    return result;
}
