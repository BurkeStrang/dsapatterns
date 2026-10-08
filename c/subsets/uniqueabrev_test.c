#include "uniqueabrev.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *word;
        const char **want;
        int want_len;
    } tests[] = {
        {"word", "word",
         STRS("word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2",
              "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4")},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        StrList got = generate_generalized_abbreviation(tt->word);
        // the abbreviations can come back in any order
        t_sort_strs((const char **)got.items, got.len);
        t_sort_strs(tt->want, tt->want_len);
        t_check_text("generate_generalized_abbreviation()",
                     t_format_strs((const char *const *)got.items, got.len),
                     t_format_strs(tt->want, tt->want_len));
        strlist_free(&got);
    }
    return t_done();
}
