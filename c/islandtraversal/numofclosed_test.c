#include "numofclosed.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *matrix;
        int want;
    } tests[] = {
        {"one simple closed island",
         "[[1,1,1,1,1],[1,0,0,0,1],[1,0,1,0,1],[1,0,0,0,1],[1,1,1,1,1]]", 1},
        {"two closed islands",
         "[[1,1,0,1,0,0],[1,0,1,0,0,0],[1,0,1,0,1,0],[1,1,0,1,0,0]]", 2},
        // top-left 0 touches border → not closed
        // the connected 0s form one island, but it is open
        {"islands touching border are NOT closed",
         "[[0,1,1,1],[1,0,0,1],[1,1,0,1],[1,1,1,1]]", 0},
        {"no land at all", "[[1,1,1],[1,1,1],[1,1,1]]", 0},
        {"all land but touches border (so zero)", "[[0,0,0],[0,0,0],[0,0,0]]",
         0},
        // the leftmost 0 in the fourth row touches the border
        // open island on the left invalidates that region
        // right-side island is fully surrounded → 1 closed
        {"complex inner islands but with border openings",
         "[[1,1,1,1,1,1],[1,0,0,0,0,1],[1,0,1,0,0,1],[0,0,0,0,1,1],[1,1,1,1,1,"
         "1]]",
         1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix matrix = t_parse_matrix(tt->matrix);
        int got = count_closed_islands(&matrix);
        t_check_int("count_closed_islands()", got, tt->want);
        intmatrix_free(&matrix);
    }
    return t_done();
}
