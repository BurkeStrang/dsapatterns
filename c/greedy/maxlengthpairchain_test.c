#include "maxlengthpairchain.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *pairs;
        int want;
    } tests[] = {
        {"Example 1", "[[1, 2], [3, 4], [2, 3]]", 2},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix pairs = t_parse_matrix(tt->pairs);
        int got = find_longest_chain(&pairs);
        t_check_int("find_longest_chain()", got, tt->want);
        intmatrix_free(&pairs);
    }
    return t_done();
}
