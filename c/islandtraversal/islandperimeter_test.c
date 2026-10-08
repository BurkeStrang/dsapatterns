#include "islandperimeter.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *matrix;
        int want;
    } tests[] = {
        // shape is a plus sign → perimeter = 12
        {"simple square island", "[[0,1,0],[1,1,1],[0,1,0]]", 12},
        {"single land cell", "[[1]]", 4},
        // ends (3 sides + 3 sides) + middle (2 + 2)
        {"single row island", "[[1,1,1,1]]", 10},
        // 2x2 block perimeter = 8
        {"one big solid block", "[[1,1],[1,1]]", 8},
        // Shape:
        // 1 .
        // 1 1
        // Perimeter = 8
        {"L-shaped island", "[[1,0],[1,1]]", 8},
        // Count exposed edges manually → perimeter = 14
        {"island touching border", "[[1,1,0],[1,0,0],[1,1,1]]", 14},
        // A hollow square → perimeter counts both outer and inner edges
        // outer = 12, inner hole = 4 → total = 16
        {"island with a hole inside", "[[1,1,1],[1,0,1],[1,1,1]]", 16},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix matrix = t_parse_matrix(tt->matrix);
        int got = find_island_perimeter(&matrix);
        t_check_int("find_island_perimeter()", got, tt->want);
        intmatrix_free(&matrix);
    }
    return t_done();
}
