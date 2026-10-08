#include "common/list.h"

#include <stdio.h>

// The results are returned in a list that the caller must free.
StrList fizz_buzz
(
    int n
)
{
    StrList res = {0};
    for (int i = 1; i <= n; i++)
    {
        if (i % 15 == 0)
        {
            strlist_push(&res, "FizzBuzz");
        }
        else if (i % 5 == 0)
        {
            strlist_push(&res, "Buzz");
        }
        else if (i % 3 == 0)
        {
            strlist_push(&res, "Fizz");
        }
        else
        {
            char number[16];
            snprintf(number, sizeof(number), "%d", i);
            strlist_push(&res, number);
        }
    }
    return res;
}
