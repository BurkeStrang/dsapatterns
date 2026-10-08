#include "quadruplesumtotarget.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int *arr;
        int arr_len;
        int target;
        const char *expected;
    } tests[] = {
        {"case 1", INTS(4, 1, 2, -1, 1, -3), 1,
         "[[-3, -1, 1, 4], [-3, 1, 1, 2]]"},
        {"case 2", INTS(2, 0, -1, 1, -2, 2), 2,
         "[[-2, 0, 2, 2], [-1, 0, 1, 2]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix result = search_quadruplets(tt->arr, tt->arr_len, tt->target);
        // the quadruplets can come back in any order
        IntMatrix expected = t_parse_matrix(tt->expected);
        t_sort_matrix(&result, true);
        t_sort_matrix(&expected, true);
        t_check_text("search_quadruplets()", t_format_matrix(&result),
                     t_format_matrix(&expected));
        intmatrix_free(&expected);
        intmatrix_free(&result);
    }
    return t_done();
}
