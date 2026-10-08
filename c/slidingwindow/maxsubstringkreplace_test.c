#include "maxsubstringkreplace.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *str;
        int k;
        int want;
    } tests[] = {
        {"Example 1", "aabccbb", 2, 5},
        {"Example 2", "abbcb", 1, 4},
        {"Example 3", "abccde", 1, 3},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = max_length_replace(tt->str, tt->k);
        t_check_int("max_length_replace()", got, tt->want);
    }
    return t_done();
}
