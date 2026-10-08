#include "frequencysort.c"

#include "testing/testing.h"

#include <limits.h>

static bool valid_frequency_sort
(
    const char *input,
    const char *output
)
{
    if (strlen(input) != strlen(output))
    {
        return false;
    }
    int freq[256] = {0};
    for (const char *c = input; *c != '\0'; c++)
    {
        freq[(unsigned char)*c]++;
    }
    int prev_freq = INT_MAX;
    const char *p = output;
    while (*p != '\0')
    {
        char c = *p;
        int count = 0;
        while (*p == c)
        {
            count++;
            p++;
        }
        if (freq[(unsigned char)c] != count || count > prev_freq)
        {
            return false;
        }
        prev_freq = count;
    }
    return true;
}

int main(void)
{
    struct test
    {
        const char *name;
        const char *s;
        // one valid answer; characters with the same frequency can come back
        // in any order
        const char *want;
    } tests[] = {
        {"Example 1", "Programming", "rrmmggainPo"},
        {"Example 2", "abcbab", "bbbaac"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char *got = sort_character_by_frequency(tt->s);
        if (got == NULL || !valid_frequency_sort(tt->s, got))
        {
            t_errorf("sort_character_by_frequency() = \"%s\", want something "
                     "like \"%s\"",
                     got == NULL ? "NULL" : got, tt->want);
        }
        free(got);
    }
    return t_done();
}
