#include "common/strbuf.h"

// You are given a string s and an integer k. Your task is to remove groups of
// identical,
// consecutive characters from the string such that each group has exactly k
// characters.
// The removal of groups should continue until it's no longer possible to make
// any more removals.
// The result should be the final version of the string after all possible
// removals have been made.
//
// Examples
//
// Input: s = "abbbaaca", k = 3
// Output: "ca"
// Explanation: First, we remove "bbb" to get "aaaca". Then, we remove "aaa" to
// get "ca".
//
// Input: s = "abbaccaa", k = 3
// Output: "abbaccaa"
// Explanation: There are no instances of 3 adjacent characters being the same.
//
// Input: s = "abbacccaa", k = 3
// Output: "abb"
// Explanation: First, we remove "ccc" to get "abbaaa". Then, we remove "aaa" to
// get "abb".
//
// Constraints:
// 1 <= s.length <= 105
// 2 <= k <= 104
// s only contains lowercase English letters.

typedef struct
{
    char chr;
    int count;
} StackElement;

// The result is a new string that the caller must free.
char *remove_duplicates_ii
(
    const char *s,
    int k
)
{
    // Initialize an empty stack to track characters and their counts. It can
    // never hold more entries than the string has characters.
    StackElement *stack = malloc((strlen(s) + 1) * sizeof(StackElement));
    int stack_len = 0;

    // Iterate through each character in the input string 's'.
    for (const char *c = s; *c != '\0'; c++)
    {
        // If the stack is not empty and the current character is the same as
        // the top of the stack.
        if (stack_len > 0 && stack[stack_len - 1].chr == *c)
        {
            // Increment the count of the top character in the stack.
            stack[stack_len - 1].count++;
        }
        else
        {
            // Otherwise, push a new character-count pair onto the stack.
            stack[stack_len++] = (StackElement){*c, 1};
        }

        // If the count of the top character in the stack reaches 'k'.
        if (stack[stack_len - 1].count == k)
        {
            stack_len--; // Remove it from the stack.
        }
    }

    // Initialize a string buffer to construct the result string.
    StrBuf result = {0};

    // Iterate through the stack and reconstruct the string from the
    // characters remaining in the stack.
    for (int i = 0; i < stack_len; i++)
    {
        for (int n = 0; n < stack[i].count; n++)
        {
            strbuf_push(&result, stack[i].chr);
        }
    }

    free(stack);
    return strbuf_take(&result); // Return the final result as a string.
}
