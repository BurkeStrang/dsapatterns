#include "common/strbuf.h"

#include <stdbool.h>

// Given a string s,
// remove all duplicate letters from the input string while maintaining the
// original order of the letters.
// Additionally,
// the returned string should be the smallest in lexicographical order among all
// possible results.
// A string is in the smallest lexicographical order if it appears first in a
// dictionary.
// For example, "abc" is smaller than "acb" because "abc" comes first
// alphabetically.
//
// Example 1
// Input: "babac"
// Expected Output: "abc"
// Justification:
// After removing 1 b and 1 a from the input string, we can get bac, and abc
// strings.
// The final answer is 'abc', which is the smallest lexicographical string
// without duplicate letters.
//
// Example 2
// Input: "zabccde"
// Expected Output: "zabcde"
// Justification: Removing one of the 'c's forms 'zabcde', the smallest string
// in lexicographical order without duplicates.
//
// Example 3
// Input: "mnopmn"
// Expected Output: "mnop"
// Justification: Removing the second 'm' and 'n' gives 'mnop', which is the
// smallest possible string without duplicate characters.

// The result is a new string that the caller must free.
char *remove_duplicate_letters
(
    const char *s
)
{
    int count[256] = {0};
    bool present[256] = {false};
    StrBuf result = {0};

    // Count the frequency of each character
    for (const char *c = s; *c != '\0'; c++)
    {
        count[(unsigned char)*c]++;
    }

    for (const char *p = s; *p != '\0'; p++)
    {
        unsigned char c = (unsigned char)*p;
        if (!present[c])
        {
            // Ensure smallest lexicographical order based off conditions of:
            // Has Result
            // Is Smaller
            // Can Remove Last
            while (result.len > 0 &&
                   c < (unsigned char)result.data[result.len - 1] &&
                   count[(unsigned char)result.data[result.len - 1]] > 0)
            {
                present[(unsigned char)strbuf_pop(&result)] = false;
            }
            strbuf_push(&result, (char)c);
            present[c] = true;
        }
        count[c]--; // Decrease the frequency
    }

    return strbuf_take(&result);
}
