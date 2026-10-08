#include "permutations.c"

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
        {"3 elements", INTS(1, 2, 3),
         "[[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix got = find_permutations(tt->nums, tt->nums_len);
        // the subsets can come back in any order
        IntMatrix want = t_parse_matrix(tt->want);
        t_sort_matrix(&got, false);
        t_sort_matrix(&want, false);
        t_check_text("find_permutations()", t_format_matrix(&got),
                     t_format_matrix(&want));
        intmatrix_free(&want);
        intmatrix_free(&got);
    }
    return t_done();
}
