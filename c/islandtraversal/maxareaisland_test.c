#include "maxareaisland.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *matrix;
        int want;
    } tests[] = {
        {"single island", "[[0,1,0,0],[1,1,0,0],[0,0,1,1],[0,0,1,1]]", 4},
        {"no island", "[[0,0,0],[0,0,0]]", 0},
        {"multiple islands", "[[1,0,0,1],[0,1,1,0],[0,0,0,1]]", 2},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix matrix = t_parse_matrix(tt->matrix);
        int got = max_area_of_island(&matrix);
        t_check_int("max_area_of_island()", got, tt->want);
        intmatrix_free(&matrix);
    }
    return t_done();
}
