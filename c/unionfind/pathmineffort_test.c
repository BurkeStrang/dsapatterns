#include "pathmineffort.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *heights;
        int want;
    } tests[] = {
        {"Example 1", "[[1, 2, 3], [3, 8, 4], [5, 3, 5]]", 1},
        {"Example 2", "[[1, 2, 2], [3, 3, 3], [5, 3, 1]]", 2},
        {"Example 3", "[[1, 1, 1], [1, 1, 1], [1, 1, 1]]", 0},
        {"One cell", "[[7]]", 0},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix heights = t_parse_matrix(tt->heights);
        int got = minimum_effort_path(&heights);
        t_check_int("minimum_effort_path()", got, tt->want);
        intmatrix_free(&heights);
    }
    return t_done();
}
