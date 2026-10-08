#include "common/strbuf.h"

// Given a string, write a function that uses a stack to reverse the string. The
// function should return the reversed string.
//
// Example 1:
// Input: "Hello, World!"
// Output: "!dlroW ,olleH"
//
// Example 2:
// Input: "OpenAI"
// Output: "IAnepO"
//
// Example 3:
// Input: "Stacks are fun!"
// Output: "!nuf era skcatS"
// Constraints:
//
// 1 <= s.length <= 105
// s[i] is a printable ascii character.

// The result is a new string that the caller must free.
char *reverse_string
(
    const char *input
)
{
    StrBuf reverse_list = {0};
    StrBuf stack = {0};
    strbuf_append(&stack, input);

    // pop all letters from stack to reverse_list
    while (stack.len > 0)
    {
        strbuf_push(&reverse_list, strbuf_pop(&stack));
    }

    strbuf_free(&stack);
    return strbuf_take(&reverse_list);
}
