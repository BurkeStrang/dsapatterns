#include <string.h>

// Given a string with lowercase letters only, if you are allowed to replace no
// more than ‘k’ letters with any letter,
// find the length of the longest substring having the same letters after
// replacement.
//
// Example 1:
// Input: str="aabccbb", k=2
// Output: 5
// Explanation: Replace the two 'c' with 'b' to have a longest repeating
// substring "bbbbb".
//
// Example 2:
// Input: str="abbcb", k=1
// Output: 4
// Explanation: Replace the 'c' with 'b' to have a longest repeating substring
// "bbbb".
//
// Example 3:
// Input: str="abccde", k=1
// Output: 3
// Explanation: Replace the 'b' or 'd' with 'c' to have the longest repeating
// substring "ccc".
// Constraints:
//
// 1 <= str.length <=
// s consists of only lowercase English letters.
// 0 <= k <= s.length

int max_length_replace
(
    const char *str,
    int k
)
{
    int str_len = (int)strlen(str);
    int window_start = 0;
    int max_length = 0;
    int max_repeat_letter_count = 0;
    int letter_frequency[256] = {0};
    // try to extend the range [window_start, window_end]
    for (int window_end = 0; window_end < str_len; window_end++)
    {
        unsigned char right_char = (unsigned char)str[window_end];
        letter_frequency[right_char]++;
        // we don't need to place the max_repeat_letter_count under the below
        // 'if', see the explanation in the 'Solution' section above.
        if (max_repeat_letter_count < letter_frequency[right_char])
        {
            max_repeat_letter_count = letter_frequency[right_char];
        }
        // current window size is from window_start to window_end, overall we
        // have a letter which is repeating 'max_repeat_letter_count' times,
        // this means we can have a window which has one letter repeating
        // 'max_repeat_letter_count' times and the remaining letters we should
        // replace. If the remaining letters are more than 'k', it is the time
        // to shrink the window as we are not allowed to replace more than 'k'
        // letters
        if (window_end - window_start + 1 - max_repeat_letter_count > k)
        {
            unsigned char left_char = (unsigned char)str[window_start];
            letter_frequency[left_char]--;
            window_start++;
        }

        if (max_length < window_end - window_start + 1)
        {
            max_length = window_end - window_start + 1;
        }
    }
    return max_length;
}
