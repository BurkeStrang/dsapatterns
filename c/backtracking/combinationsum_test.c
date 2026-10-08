#include "combinationsum.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *candidates;
        int candidates_len;
        int target;
        const char *want;
    } tests[] = {
        {"test1", INTS(2, 3, 6, 7), 7, "[[2, 2, 3], [7]]"},
        {"test2", INTS(2, 4, 6, 8), 10,
         "[[2, 2, 2, 2, 2], [2, 2, 2, 4], [2, 2, 6], [2, 4, 4], [2, 8], [4, "
         "6]]"},
        {"test3", INTS(2), 1, "[]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix got =
            combination_sum(tt->candidates, tt->candidates_len, tt->target);
        t_check_matrix("combination_sum()", &got, tt->want);
        intmatrix_free(&got);
    }
    return t_done();
}
