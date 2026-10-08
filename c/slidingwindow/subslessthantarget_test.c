#include "subslessthantarget.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *arr;
        int arr_len;
        int target;
        const char *want;
    } tests[] = {
        {"Example 1", INTS(2, 5, 3, 10), 30,
         "[[2], [2, 5], [5], [5, 3], [3], [10]]"},
        {"Example 2", INTS(8, 2, 6, 5), 50,
         "[[8], [8, 2], [2], [2, 6], [6], [6, 5], [5]]"},
        {"Target 0", INTS(10, 5, 2, 6), 0, "[]"},
        {"Single element < target", INTS(1), 2, "[[1]]"},
        {"Single element >= target", INTS(5), 5, "[]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix got = find_subarrays(tt->arr, tt->arr_len, tt->target);
        // the subarrays can come back in any order
        IntMatrix want = t_parse_matrix(tt->want);
        t_sort_matrix(&got, false);
        t_sort_matrix(&want, false);
        t_check_text("find_subarrays()", t_format_matrix(&got),
                     t_format_matrix(&want));
        intmatrix_free(&want);
        intmatrix_free(&got);
    }
    return t_done();
}
