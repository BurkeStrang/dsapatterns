#include "common/map.h"

// Given a string s and an array of words words.
// Break string s into multiple non-overlapping substrings such that each
// substring should be part of the words.
// There are some characters left which are not part of any substring.
// Return the minimum number of remaining characters in s,
// which are not part of any substring after string break-up.
//
// Example 1:
// Input: s = "amazingracecar", dictionary = ["race", "car"]
// Expected Output: 7
// Justification: The string s can be rearranged to form "racecar", leaving 'a',
// 'm', 'a', 'z', 'i', 'n', 'g' as extra.
//
// Example 2:
// Input: s = "bookkeeperreading", dictionary = ["keep", "read"]
// Expected Output: 9
// Justification: The words "keep" and "read" can be formed from s, but 'b',
// 'o', 'o', 'k', 'e', 'r', 'i', 'n', 'g' are extra.
//
// Example 3:
// Input: s = "thedogbarksatnight", dictionary = ["dog", "bark", "night"]
// Expected Output: 6
// Justification: The words "dog", "bark", and "night" can be formed, leaving
// 't', 'h', 'e', 's', 'a', 't' as extra characters.
//
// Constraints:
// 1 <= str.length <= 50
// 1 <= dictionary.length <= 50
// 1 <= dictionary[i].length <= 50
// dictionary[i] and s consists of only lowercase English letters
// dictionary contains distinct words

typedef struct
{
    int *memo;
    StrMap word_set;
} MinChar;

int solve
(
    MinChar *sol,
    int index,
    int length,
    const char *s
)
{
    // Base case: when we reach the end of the string
    if (index == length)
    {
        return 0;
    }

    // Return the cached result if already computed
    if (sol->memo[index] != -1)
    {
        return sol->memo[index];
    }

    // Count the current character as an extra character
    int min_extra = solve(sol, index + 1, length, s) + 1;

    // Try forming substrings starting from the current index
    char *substring = malloc((size_t)length + 1);
    for (int end = index; end < length; end++)
    {
        // Current substring
        memcpy(substring, s + index, (size_t)(end - index + 1));
        substring[end - index + 1] = '\0';
        // Check if the substring is in the dictionary
        if (strmap_has(&sol->word_set, substring))
        {
            // Update minimum extra characters
            int extra = solve(sol, end + 1, length, s);
            if (extra < min_extra)
            {
                min_extra = extra;
            }
        }
    }
    free(substring);

    // Store the result in the memo and return
    sol->memo[index] = min_extra;
    return min_extra;
}

int min_extra_char
(
    const char *s,
    const char *const *dictionary,
    int dictionary_len
)
{
    int length = (int)strlen(s);
    MinChar sol = {0};
    sol.memo = malloc(((size_t)length + 1) * sizeof(int));
    for (int i = 0; i < length; i++)
    {
        sol.memo[i] = -1; // Initialize memoization array with -1
    }
    for (int i = 0; i < dictionary_len; i++)
    {
        // Populate map with dictionary words
        strmap_set(&sol.word_set, dictionary[i], 1);
    }

    int result = solve(&sol, 0, length, s);
    strmap_free(&sol.word_set);
    free(sol.memo);
    return result;
}
