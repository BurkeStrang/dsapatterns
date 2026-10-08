#include "ksmallestsortedmatrix.c"

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
        {"Example 1", "[[2, 6, 8], [3, 7, 10], [5, 7, 8]]", 5, 7},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix lists = t_parse_matrix(tt->lists);
        int got = find_kth_smallest_point(&lists, tt->k);
        t_check_int("find_kth_smallest_point()", got, tt->want);
        intmatrix_free(&lists);
    }
    return t_done();
}
