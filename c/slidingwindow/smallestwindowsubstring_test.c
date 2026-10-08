#include "smallestwindowsubstring.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *str;
        const char *pattern;
        const char *want;
    } tests[] = {
        {"Example 1", "aabdec", "abc", "abdec"},
        {"Example 2", "aabdec", "abac", "aabdec"},
        {"Example 3", "abdbca", "abc", "bca"},
        {"Example 4", "adcad", "abc", ""},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char *got = find_substring(tt->str, tt->pattern);
        t_check_str("find_substring()", got, tt->want);
        free(got);
    }
    return t_done();
}
