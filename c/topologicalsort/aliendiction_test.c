#include "aliendiction.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *const *words;
        int words_len;
        const char *want;
    } tests[] = {
        {"Example 1", STRS("ba", "bc", "ac", "cab"), "bac"},
        {"Example 2", STRS("cab", "aaa", "aab"), "cab"},
        {"Example 3", STRS("ywx", "wz", "xww", "xz", "zyy", "zwz"), "ywxz"},
        {"Word before its own prefix", STRS("abc", "ab"), ""},
        {"Cyclic ordering", STRS("a", "b", "a"), ""},
        {"No words", NO_STRS, ""},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char *got = find_alien_order(tt->words, tt->words_len);
        t_check_str("find_alien_order()", got, tt->want);
        free(got);
    }
    return t_done();
}
