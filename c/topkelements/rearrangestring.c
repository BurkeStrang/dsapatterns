#include <stdlib.h>
#include <string.h>

// Given a string,
// find if its letters can be rearranged in such a way that no two same
// characters come next to each other.
//
// Example 1:
// Input: "aappp"
// Output: "papap"
// Explanation: In "papap", none of the repeating characters come next to each
// other.
//
// Example 2:
// Input: "Programming"
// Output: "rgmrgmPiano" or "gmringmrPoa" or "gmrPagimnor", etc.
// Explanation: None of the repeating characters come next to each other.
//
// Example 3:
// Input: "aapa"
// Output: ""
// Explanation: In all arrangements of "aapa", atleast two 'a' will come
// together e.g., "apaa", "paaa".

typedef struct
{
    char chr;
    int count;
} CharFrequency;

// sorts by count, highest first
int compare_count_descending
(
    const void *a,
    const void *b
)
{
    const CharFrequency *x = a;
    const CharFrequency *y = b;
    return (y->count > x->count) - (y->count < x->count);
}

// The result is a new string that the caller must free; it is empty when the
// letters can't be rearranged.
char *rearrange_string
(
    const char *str
)
{
    int str_len = (int)strlen(str);
    int char_frequency[256] = {0};
    for (int i = 0; i < str_len; i++)
    {
        char_frequency[(unsigned char)str[i]]++;
    }

    // the list never holds more than one entry per different character
    CharFrequency char_frequencies[257];
    int len = 0;
    for (int chr = 0; chr < 256; chr++)
    {
        if (char_frequency[chr] > 0)
        {
            char_frequencies[len++] =
                (CharFrequency){(char)chr, char_frequency[chr]};
        }
    }

    qsort(char_frequencies, (size_t)len, sizeof(char_frequencies[0]),
          compare_count_descending);

    char *result_string = malloc((size_t)str_len + 1);
    int index = 0;
    char previous_char = '\0';

    while (len > 0)
    {
        char current_char = char_frequencies[0].chr;
        int count = char_frequencies[0].count;
        // take the first entry off the list
        memmove(char_frequencies, char_frequencies + 1,
                (size_t)(len - 1) * sizeof(char_frequencies[0]));
        len--;

        // Check if the previous character can be added back to the list
        if (previous_char != '\0' &&
            char_frequency[(unsigned char)previous_char] > 0)
        {
            char_frequencies[len++] = (CharFrequency){
                previous_char, char_frequency[(unsigned char)previous_char]};
        }

        // Append the current character to the result string and decrement its
        // count
        result_string[index] = current_char;
        index++;
        char_frequency[(unsigned char)current_char]--;
        previous_char = current_char;

        // Sort the char_frequencies to maintain the heap property
        qsort(char_frequencies, (size_t)len, sizeof(char_frequencies[0]),
              compare_count_descending);

        // If all characters are used up, break the loop
        if (count == 1 && len == 0)
        {
            break;
        }
    }

    // If we were successful in appending all the characters to the result
    // string, return it
    if (index != str_len)
    {
        index = 0;
    }
    result_string[index] = '\0';
    return result_string;
}
