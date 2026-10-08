#include "removedup.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *s;
        const char *want;
    } tests[] = {
        {"Example 1", "babac", "abc"},
        {"Example 2", "zabccde", "zabcde"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char *got = remove_duplicate_letters(tt->s);
        t_check_str("remove_duplicate_letters()", got, tt->want);
        free(got);
    }
    return t_done();
}
