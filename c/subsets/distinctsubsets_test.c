#include "distinctsubsets.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int *nums;
        int nums_len;
        const char *want;
    } tests[] = {
        {"example test case 1", INTS(1, 3), "[[], [1], [3], [1, 3]]"},
        {"example test case 2", INTS(1, 2, 3),
         "[[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix got = find_subsets(tt->nums, tt->nums_len);
        // the subsets can come back in any order
        IntMatrix want = t_parse_matrix(tt->want);
        t_sort_matrix(&got, true);
        t_sort_matrix(&want, true);
        t_check_text("find_subsets()", t_format_matrix(&got),
                     t_format_matrix(&want));
        intmatrix_free(&want);
        intmatrix_free(&got);
    }
    return t_done();
}
