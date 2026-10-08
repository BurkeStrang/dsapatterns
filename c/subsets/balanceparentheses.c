#include "common/list.h"
#include "common/queue.h"

#include <stdio.h>

typedef struct
{
    char *str;       // owned by the queue entry
    int open_count;  // open parentheses count
    int close_count; // close parentheses count
} ParenthesesString;

// with_added returns a new string made of str followed by c.
char *with_added
(
    const char *str,
    char c
)
{
    size_t len = strlen(str);
    char *result = malloc(len + 2);
    memcpy(result, str, len);
    result[len] = c;
    result[len + 1] = '\0';
    return result;
}

// The combinations are returned in a list that the caller must free.
StrList generate_valid_parentheses
(
    int num
)
{
    StrList result = {0};
    Queue queue = queue_new(sizeof(ParenthesesString));
    queue_push(&queue, &(ParenthesesString){str_copy(""), 0, 0});
    while (queue.len > 0)
    {
        ParenthesesString ps;
        queue_pop(&queue, &ps);
        // if we've reached the maximum number of open and close parentheses,
        // add to result
        if (ps.open_count == num && ps.close_count == num)
        {
            strlist_push(&result, ps.str);
        }
        else
        {
            // if we can add an open parentheses, add it
            if (ps.open_count < num)
            {
                queue_push(&queue, &(ParenthesesString){with_added(ps.str, '('),
                                                        ps.open_count + 1,
                                                        ps.close_count});
            }

            // if we can add a close parentheses, add it
            if (ps.open_count > ps.close_count)
            {
                queue_push(&queue, &(ParenthesesString){with_added(ps.str, ')'),
                                                        ps.open_count,
                                                        ps.close_count + 1});
            }
        }
        free(ps.str);
    }
    queue_free(&queue);
    return result;
}
