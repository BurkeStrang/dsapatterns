#include "smallestrange.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *input_lists;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", "[[1, 5, 8], [4, 12], [7, 8, 10]]", INTS(4, 7)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix input_lists = t_parse_matrix(tt->input_lists);
        int *got = find_smallest_range(&input_lists);
        t_check_ints("find_smallest_range()", got, 2, tt->want, tt->want_len);
        free(got);
        intmatrix_free(&input_lists);
    }
    return t_done();
}
