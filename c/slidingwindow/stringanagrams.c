#include "common/list.h"

#include <stdbool.h>
#include <string.h>

// Given a string and a pattern, find all anagrams of the pattern in the given
// string.
// Every anagram is a permutation of a string.
// As we know, when we are not allowed to repeat characters while finding
// permutations of a string,
// we get  permutations (or anagrams) of a string having  characters. For
// example, here are the six anagrams of the string abc:
//
// abc
// acb
// bac
// bca
// cab
// cba
//
// Write a function to return a list of starting indices of the anagrams of the
// pattern in the given string.
//
// Example 1:
// Input: str="ppqp", pattern="pq"
// Output: [1, 2]
// Explanation: The two anagrams of the pattern in the given string are "pq" and
// "qp".
//
// Example 2:
// Input: str="abbcabc", pattern="abc"
// Output: [2, 3, 4]
// Explanation: The three anagrams of the pattern in the given string are "bca",
// "cab", and "abc".
//
// Constraints:
// 1 <= s.length, p.length <= 3 * 104
// str and pattern consist of lowercase English letters.

// The starting indices are returned in a list that the caller must free.
IntList find_string_anagrams
(
    const char *str,
    const char *pattern
)
{
    int str_len = (int)strlen(str);
    int pattern_len = (int)strlen(pattern);
    int window_start = 0;
    int matched = 0;
    // how many of each pattern character we still need, which characters are
    // part of the pattern, and how many distinct characters it has
    int char_frequency[256] = {0};
    bool in_pattern[256] = {false};
    int distinct = 0;
    for (int i = 0; i < pattern_len; i++)
    {
        unsigned char chr = (unsigned char)pattern[i];
        char_frequency[chr]++;
        if (!in_pattern[chr])
        {
            in_pattern[chr] = true;
            distinct++;
        }
    }

    IntList result_indices = {0};
    // our goal is to match all the characters from the map with the current
    // window
    for (int window_end = 0; window_end < str_len; window_end++)
    {
        unsigned char right_char = (unsigned char)str[window_end];
        // decrement the frequency of the matched character
        if (in_pattern[right_char])
        {
            char_frequency[right_char]--;
            if (char_frequency[right_char] == 0)
            {
                matched++;
            }
        }

        if (matched == distinct)
        { // have we found an anagram?
            intlist_push(&result_indices, window_start);
        }

        if (window_end >= pattern_len - 1)
        { // shrink the window
            unsigned char left_char = (unsigned char)str[window_start];
            window_start++;
            if (in_pattern[left_char])
            {
                if (char_frequency[left_char] == 0)
                {
                    // before putting the character back, decrement the
                    // matched count
                    matched--;
                }
                // put the character back
                char_frequency[left_char]++;
            }
        }
    }

    return result_indices;
}
