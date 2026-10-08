#include "removekdigits.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *s;
        int k;
        const char *want;
    } tests[] = {
        {"Example 1", "1432219", 3, "1219"},
        {"Example 2", "10200", 1, "200"},
        {"Example 3", "1901042", 4, "2"},
        {"Remove all digits", "10", 2, "0"},
        {"Leading zeros after removal", "100200", 1, "200"},
        {"No removal needed", "12345", 0, "12345"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char *got = remove_k_digits(tt->s, tt->k);
        t_check_str("remove_k_digits()", got, tt->want);
        free(got);
    }
    return t_done();
}
