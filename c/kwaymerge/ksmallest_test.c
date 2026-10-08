#include "ksmallest.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *lists;
        int k;
        int want;
    } tests[] = {
        {"Example 1", "[[2, 6, 8], [3, 6, 7], [1, 3, 4]]", 5, 4},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix lists = t_parse_matrix(tt->lists);
        int got = find_kth_smallest(&lists, tt->k);
        t_check_int("find_kth_smallest()", got, tt->want);
        intmatrix_free(&lists);
    }
    return t_done();
}
