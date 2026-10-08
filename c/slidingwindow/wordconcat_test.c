#include "wordconcat.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *str;
        const char *const *words;
        int words_count;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", "catfoxcat", STRS("cat", "fox"), INTS(0, 3)},
        {"Example 2", "catcatfoxfox", STRS("cat", "fox"), INTS(3)},
        {"No match", "abcdefg", STRS("hi", "jk"), NO_INTS},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList got =
            find_word_concatenation(tt->str, tt->words, tt->words_count);
        t_check_ints("find_word_concatenation()", got.items, got.len, tt->want,
                     tt->want_len);
        intlist_free(&got);
    }
    return t_done();
}
