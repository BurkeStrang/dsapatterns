#include "common/list.h"
#include "common/strbuf.h"

// Given an absolute file path in a Unix-style file system,
// simplify it by converting ".." to the previous directory and removing any "."
// or multiple slashes.
// The resulting string should represent the shortest absolute path.
//
// Example 1
// Input: path = "/a//b////c/d//././/.."
// Expected Output: "/a/b/c"
// Explanation:
// Convert multiple slashes (//) into single slashes (/).
// "." refers to the current directory and is ignored.
// ".." moves up one directory, so "d" is removed.
// The simplified path is "/a/b/c".
//
// Example 2
// Input: path = "/../"
// Expected Output: "/"
// Explanation:
// ".." moves up one directory, but we are already at the root ("/"), so nothing
// happens.
// The final simplified path remains "/".
//
// Example 3
// Input: path = "/home//foo/"
// Expected Output: "/home/foo"
// Explanation:
// Convert multiple slashes (//) into single slashes (/).
// The final simplified path is "/home/foo".
//
// Constraints:
// 1 <= path.length <= 3000
// path consists of English letters, digits, period '.', slash '/' or '_'.
// path is a valid absolute Unix path.

// The result is a new string that the caller must free.
char *simplify_path
(
    const char *path
)
{
    // Create a stack to store the simplified path components
    StrList stack = {0};

    // Split the input path string using '/' as a delimiter
    const char *p = path;
    while (*p != '\0')
    {
        const char *end = strchr(p, '/');
        if (end == NULL)
        {
            end = p + strlen(p);
        }
        char component[256];
        size_t len = (size_t)(end - p);
        memcpy(component, p, len);
        component[len] = '\0';

        if (strcmp(component, "..") == 0)
        {
            // If the component is '..', pop the last component from the stack
            if (stack.len > 0)
            {
                free(stack.items[--stack.len]);
            }
        }
        else if (len > 0 && strcmp(component, ".") != 0)
        {
            // If the component is not empty and not '.', push it onto the
            // stack
            strlist_push(&stack, component);
        }

        p = *end == '/' ? end + 1 : end;
    }

    // Reconstruct the simplified path by joining components from the stack
    StrBuf result = {0};
    strbuf_push(&result, '/');
    for (int i = 0; i < stack.len; i++)
    {
        if (i > 0)
        {
            strbuf_push(&result, '/');
        }
        strbuf_append(&result, stack.items[i]);
    }

    strlist_free(&stack);
    return strbuf_take(&result);
}
