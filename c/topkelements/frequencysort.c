#include <stdlib.h>
#include <string.h>

// Given a string, sort it based on the decreasing frequency of its characters.
//
// Example 1:
// Input: "Programming"
// Output: "rrggmmPiano"
// Explanation: 'r', 'g', and 'm' appeared twice, so they need to appear before
// any other character.
//
// Example 2:
// Input: "abcbab"
// Output: "bbbaac"
// Explanation: 'b' appeared three times, 'a' appeared twice, and 'c' appeared
// only once.

typedef struct
{
    char character;
    int frequency;
} CharacterFrequency;

// sorts by frequency, highest first
int compare_frequency_descending
(
    const void *a,
    const void *b
)
{
    const CharacterFrequency *x = a;
    const CharacterFrequency *y = b;
    return (y->frequency > x->frequency) - (y->frequency < x->frequency);
}

// The result is a new string that the caller must free.
char *sort_character_by_frequency
(
    const char *str
)
{
    // Find the frequency of each character
    int character_frequency[256] = {0};
    for (const char *chr = str; *chr != '\0'; chr++)
    {
        character_frequency[(unsigned char)*chr]++;
    }

    // Create an array of character-frequency pairs for sorting
    CharacterFrequency pairs[256];
    int pairs_len = 0;
    for (int chr = 0; chr < 256; chr++)
    {
        if (character_frequency[chr] > 0)
        {
            pairs[pairs_len++] =
                (CharacterFrequency){(char)chr, character_frequency[chr]};
        }
    }

    // Sort the character-frequency pairs by frequency in descending order
    qsort(pairs, (size_t)pairs_len, sizeof(pairs[0]),
          compare_frequency_descending);

    // Build a string, appending the most occurring characters first
    char *sorted_string = malloc(strlen(str) + 1);
    int len = 0;
    for (int p = 0; p < pairs_len; p++)
    {
        for (int i = 0; i < pairs[p].frequency; i++)
        {
            sorted_string[len++] = pairs[p].character;
        }
    }
    sorted_string[len] = '\0';

    return sorted_string;
}
