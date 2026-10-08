#include "tripletessumzero.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int *input;
        int input_len;
        const char *expected;
    } tests[] = {
        {"case 1", INTS(-3, 0, 1, 2, -1, 1, -2),
         "[[-3, 1, 2], [-2, 0, 2], [-2, 1, 1], [-1, 0, 1]]"},
        {"case 2", INTS(-5, 2, -1, -2, 3), "[[-5, 2, 3], [-2, -1, 3]]"},
        {"case 3", INTS(1, 2, 3), "[]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix got = search_triplets(tt->input, tt->input_len);
        // the triplets can come back in any order
        IntMatrix expected = t_parse_matrix(tt->expected);
        t_sort_matrix(&got, true);
        t_sort_matrix(&expected, true);
        t_check_text("search_triplets()", t_format_matrix(&got),
                     t_format_matrix(&expected));
        intmatrix_free(&expected);
        intmatrix_free(&got);
    }
    return t_done();
}
