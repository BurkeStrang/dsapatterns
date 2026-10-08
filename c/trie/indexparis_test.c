#include "indexparis.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *text;
        const char *const *words;
        int words_len;
        const char *want;
    } tests[] = {
        {"Test Case 1", "thestarsareout", STRS("star", "stars", "are"),
         "[[3, 6], [3, 7], [8, 10]]"},
        {"Test Case 2", "bluebirdskyscraper", STRS("blue", "bird", "sky"),
         "[[0, 3], [4, 7], [8, 10]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix got = index_pairs(tt->text, tt->words, tt->words_len);
        t_check_matrix("index_pairs()", &got, tt->want);
        intmatrix_free(&got);
    }
    return t_done();
}
