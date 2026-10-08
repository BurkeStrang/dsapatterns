#include "common/list.h"
#include "common/map.h"

#include <string.h>

// You’re given a string s and a list of words words, where all words have the
// same length.
//
// A concatenated substring is formed by joining all the words from any
// permutation of words — each used exactly once,
// without any extra characters in between.
//
// For example, if words = ["ab", "cd", "ef"], then valid concatenated strings
// include
// "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab".
// A string like "acdbef" is not valid because it doesn't match any complete
// permutation of the given words.
//
// Return all starting indices in s where such concatenated substrings appear.
// You can return the indices in any order.
//
// Example 1:
// Input: String="catfoxcat", Words=["cat", "fox"]
// Output: [0, 3]
// Explanation: The two substring containing both the words are "catfox" &
// "foxcat".
//
// Example 2:
// Input: String="catcatfoxfox", Words=["cat", "fox"]
// Output: [3]
// Explanation: The only substring containing both the words is "catfox".
//
// Constraints:
// 1 <= words.length <= 104
// 1 <= words[i].length <= 30
// words[i] consists of only lowercase English letters.
// All the strings of words are unique.
// 1 <= sum(words[i].length) <= 105

// The starting indices are returned in a list that the caller must free.
IntList find_word_concatenation
(
    const char *str,
    const char *const *words,
    int words_count
)
{
    int str_len = (int)strlen(str);
    StrMap word_frequency_map = {0};
    for (int i = 0; i < words_count; i++)
    {
        strmap_add(&word_frequency_map, words[i], 1);
    }

    IntList result_indices = {0};
    int word_length = (int)strlen(words[0]);
    char word[64]; // words are at most 30 characters long

    for (int i = 0; i <= str_len - words_count * word_length; i++)
    {
        StrMap words_seen = {0};
        for (int j = 0; j < words_count; j++)
        {
            int next_word_index = i + j * word_length;
            // get the next word from the string
            memcpy(word, str + next_word_index, (size_t)word_length);
            word[word_length] = '\0';
            // break if we don't need this word
            if (!strmap_has(&word_frequency_map, word))
            {
                break;
            }
            // add the word to the 'words_seen' map
            int seen = strmap_add(&words_seen, word, 1);
            // no need to process further if the word has higher frequency
            // than required
            if (seen > strmap_get(&word_frequency_map, word))
            {
                break;
            }
            // store index if we have found all the words
            if (j + 1 == words_count)
            {
                intlist_push(&result_indices, i);
            }
        }
        strmap_free(&words_seen);
    }
    strmap_free(&word_frequency_map);
    return result_indices;
}
