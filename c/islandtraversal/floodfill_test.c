#include "floodfill.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *matrix;
        int x;
        int y;
        int new_color;
        const char *want;
    } tests[] = {
        {"basic flood fill", "[[1,1,1],[1,1,0],[1,0,1]]", 1, 1, 2,
         "[[2,2,2],[2,2,0],[2,0,1]]"},
        {"starting point already new color", "[[0,0],[0,1]]", 1, 1, 1,
         "[[0,0],[0,1]]"},
        // x is outside the grid
        {"no fill when starting outside bounds", "[[1,1],[1,1]]", 3, 0, 5,
         "[[1,1],[1,1]]"},
        {"single cell matrix", "[[1]]", 0, 0, 9, "[[9]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix matrix = t_parse_matrix(tt->matrix);
        IntMatrix *got = flood_fill(&matrix, tt->x, tt->y, tt->new_color);
        if (got == NULL)
        {
            t_errorf("flood_fill() = NULL, want %s", tt->want);
        }
        else
        {
            t_check_matrix("flood_fill()", got, tt->want);
        }
        intmatrix_free(&matrix);
    }
    return t_done();
}
