#include "common/strbuf.h"

// You are given a string s consisting of lowercase English letters. A duplicate
// removal consists of choosing two adjacent and equal letters and removing
// them.
//
// We repeatedly make duplicate removals on s until we no longer can.
//
// Return the final string after all such duplicate removals have been made.
//
// Examples
//
// Input: s = "abccba"
// Output: ""
// Explanation: First, we remove "cc" to get "abba". Then, we remove "bb" to get
// "aa". Finally, we remove "aa" to get an empty string.
// Input: s = "foobar"
// Output: "fbar"
// Explanation: We remove "oo" to get "fbar".
// Input: s = "fooobar"
// Output: "fobar"
// Explanation: We remove the pair "oo" to get "fobar".
// Input: s = "abcd"
// Output: "abcd"
// Explanation: No adjacent duplicates so no changes.
// Constraints:
//
// 1 <= s.length <= 105
// s consists of lowercase English letters.

// The result is a new string that the caller must free.
char *remove_duplicates
(
    const char *s
)
{
    // Create a string buffer to use as a stack
    StrBuf stack = {0};

    // Process each character in s
    for (const char *c = s; *c != '\0'; c++)
    {
        // If the stack is not empty and the current character is the same as
        // the top of the stack, pop the character from the stack
        if (stack.len > 0 && *c == stack.data[stack.len - 1])
        {
            strbuf_pop(&stack);
        }
        else
        {
            // Push the current character onto the stack
            strbuf_push(&stack, *c);
        }
    }

    // Convert the stack to a string
    return strbuf_take(&stack);
}
