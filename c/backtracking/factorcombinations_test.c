#include "factorcombinations.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int n;
        const char *want;
    } tests[] = {
        {"Example 1", 8, "[[2, 2, 2], [2, 4]]"},
        {"Example 2", 20, "[[2, 2, 5], [2, 10], [4, 5]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix got = get_factors(tt->n);
        // the combinations can come back in any order
        IntMatrix want = t_parse_matrix(tt->want);
        t_sort_matrix(&got, true);
        t_sort_matrix(&want, true);
        t_check_text("get_factors()", t_format_matrix(&got),
                     t_format_matrix(&want));
        intmatrix_free(&want);
        intmatrix_free(&got);
    }
    return t_done();
}
