#include "flipandinvert.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *arr;
        const char *want;
    } tests[] = {
        {"Example 1", "[[1,0,1],[1,1,1],[0,1,1]]", "[[0,1,0],[0,0,0],[0,0,1]]"},
        {"Example 2", "[[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]",
         "[[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]"},
        {"Single row", "[[1,0,0,1]]", "[[0,1,1,0]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix arr = t_parse_matrix(tt->arr);
        IntMatrix *got = flip_and_invert_image(&arr);
        if (got == NULL)
        {
            t_errorf("flip_and_invert_image() = NULL, want %s", tt->want);
        }
        else
        {
            t_check_matrix("flip_and_invert_image()", got, tt->want);
        }
        intmatrix_free(&arr);
    }
    return t_done();
}
