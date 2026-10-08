#include "permutationsinstring.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *str;
        const char *pattern;
        bool want;
    } tests[] = {
        {"Example 1", "oidbcaf", "abc", true},
        {"Example 2", "odicf", "dc", false},
        {"Example 3", "bcdxabcdy", "bcdyabcdx", true},
        {"Example 4", "aaacb", "abc", true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        bool got = find_permutation(tt->str, tt->pattern);
        t_check_bool("find_permutation()", got, tt->want);
    }
    return t_done();
}
