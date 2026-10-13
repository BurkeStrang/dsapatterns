#include "common/list.h"
#include "common/queue.h"

#include <stdbool.h>
#include <string.h>

// There is a dictionary containing words from an alien language
// for which we don't know the ordering of the letters.
// Given a list of strings words from the alien language's dictionary.
// All strings in words are sorted lexicographically by the rules of this new
// language.
// Return a string of the unique letters in the new alien language
// sorted in lexicographically increasing order by the new language's rules.
// It is given that the input is a valid dictionary and there exists an ordering
// among its letters.
//
// Example 1:
// Input: Words: ["ba", "bc", "ac", "cab"]
// Output: bac
// Explanation: Given that the words are sorted lexicographically by the rules
// of the alien language, so
// from the given words we can conclude the following ordering among its
// characters:
// 1. From "ba" and "bc", we can conclude that 'a' comes before 'c'.
// 2. From "bc" and "ac", we can conclude that 'b' comes before 'a'
// From the above two points, we can conclude that the correct character order
// is: "bac"
//
// Example 2:
// Input: Words: ["cab", "aaa", "aab"]
// Output: cab
// Explanation: From the given words we can conclude the following ordering
// among its characters:
// 1. From "cab" and "aaa", we can conclude that 'c' comes before 'a'.
// 2. From "aaa" and "aab", we can conclude that 'a' comes before 'b'
// From the above two points, we can conclude that the correct character order
// is: "cab"
//
// Example 3:
// Input: Words: ["ywx", "wz", "xww", "xz", "zyy", "zwz"]
// Output: ywxz
// Explanation: From the given words we can conclude the following ordering
// among its characters:
// 1. From "ywx" and "wz", we can conclude that 'y' comes before 'w'.
// 2. From "wz" and "xww", we can conclude that 'w' comes before 'x'.
// 3. From "xww" and "xz", we can conclude that 'w' comes before 'z'
// 4. From "xz" and "zyy", we can conclude that 'x' comes before 'z'
// 5. From "zyy" and "zwz", we can conclude that 'y' comes before 'w'
//
// From the above five points, we can conclude that the correct character order
// is: "ywxz"
// Constraints:
// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of only lowercase English letters.

#define ALPHABET 26

// The order is returned as a new string that the caller must free; it is
// empty when the words don't describe a valid ordering.
char *find_alien_order
(
    const char *const *words,
    int words_len
)
{
    char *sorted_order = calloc(ALPHABET + 1, sizeof(char));
    if (words_len == 0)
    {
        return sorted_order;
    }

    // a. Initialize the graph
    bool present[ALPHABET] = {false};
    int in_degree[ALPHABET] = {0};
    IntList graph[ALPHABET] = {0};
    // letters in the order they first appear, so the sources are always
    // visited in the same order
    int letters[ALPHABET];
    int letters_len = 0;
    for (int i = 0; i < words_len; i++)
    {
        for (const char *p = words[i]; *p != '\0'; p++)
        {
            int character = *p - 'a';
            if (!present[character])
            {
                present[character] = true;
                letters[letters_len++] = character;
            }
        }
    }

    // b. Build the graph
    bool valid = true;
    for (int i = 0; valid && i < words_len - 1; i++)
    {
        // find ordering of characters from adjacent words
        const char *w1 = words[i];
        const char *w2 = words[i + 1];
        int len1 = (int)strlen(w1);
        int len2 = (int)strlen(w2);
        bool found_difference = false;
        for (int j = 0; j < len1 && j < len2; j++)
        {
            int parent = w1[j] - 'a';
            int child = w2[j] - 'a';
            if (parent != child)
            {
                intlist_push(&graph[parent], child);
                in_degree[child]++;
                found_difference = true;
                break;
            }
        }
        // a word cannot come before one of its own prefixes: "abc" before
        // "ab" is not a valid dictionary, so no letter ordering can explain it
        if (!found_difference && len1 > len2)
        {
            valid = false;
        }
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    Queue sources = queue_new(sizeof(int));
    for (int i = 0; valid && i < letters_len; i++)
    {
        if (in_degree[letters[i]] == 0)
        {
            int_queue_push(&sources, letters[i]);
        }
    }

    // d. For each source, add it to the sorted_order and subtract one from
    // all of its children's in-degrees. If a child's in-degree becomes zero,
    // add it to sources queue.
    int sorted_len = 0;
    while (sources.len > 0)
    {
        int vertex = int_queue_pop(&sources);
        sorted_order[sorted_len++] = (char)('a' + vertex);
        for (int c = 0; c < graph[vertex].len; c++)
        {
            int child = graph[vertex].items[c];
            in_degree[child]--;
            if (in_degree[child] == 0)
            {
                int_queue_push(&sources, child);
            }
        }
    }

    queue_free(&sources);
    for (int i = 0; i < ALPHABET; i++)
    {
        intlist_free(&graph[i]);
    }

    // if sorted_order doesn't contain all characters, there is a cyclic
    // dependency between characters, therefore, we will not be able to find
    // the correct ordering of the characters
    if (sorted_len != letters_len)
    {
        sorted_len = 0;
    }
    sorted_order[sorted_len] = '\0';
    return sorted_order;
}
