#include "stringanagrams.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *str;
        const char *pattern;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", "ppqp", "pq", INTS(1, 2)},
        {"Example 2", "abbcabc", "abc", INTS(2, 3, 4)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList got = find_string_anagrams(tt->str, tt->pattern);
        t_check_ints("find_string_anagrams()", got.items, got.len, tt->want,
                     tt->want_len);
        intlist_free(&got);
    }
    return t_done();
}
