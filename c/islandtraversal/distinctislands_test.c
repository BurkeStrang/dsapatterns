#include "distinctislands.c"

#include "islandtraversal/shared.h"
#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *matrix;
        int want;
    } tests[] = {
        {"two distinct islands", "[[1,1,0,0,0],[1,0,0,1,1],[0,0,0,1,1]]", 2},
        {"all islands same shape", "[[1,0,1,0],[1,0,1,0]]", 1},
        {"no islands", "[[0,0],[0,0]]", 0},
        {"single island", "[[1,1],[1,1]]", 1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix matrix = t_parse_matrix(tt->matrix);
        int got = find_distinct_islands_dfs(&matrix);
        t_check_int("find_distinct_islands_dfs()", got, tt->want);
        intmatrix_free(&matrix);
    }
    return t_done();
}
