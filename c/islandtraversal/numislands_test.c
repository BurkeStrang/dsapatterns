#include "numislands.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *matrix;
        int want;
    } tests[] = {
        {"single island", "[[1,1,0,0],[1,1,0,0],[0,0,1,0],[0,0,0,1]]", 3},
        {"no islands", "[[0,0,0],[0,0,0]]", 0},
        {"all land", "[[1,1],[1,1]]", 1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix matrix = t_parse_matrix(tt->matrix);
        int got = count_islands(&matrix);
        t_check_int("count_islands()", got, tt->want);
        intmatrix_free(&matrix);
    }
    return t_done();
}
