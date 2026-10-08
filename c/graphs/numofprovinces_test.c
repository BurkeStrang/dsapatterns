#include "numofprovinces.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *is_connected;
        int want;
    } tests[] = {
        {"Example 1: Two provinces", "[[1, 1, 0], [1, 1, 0], [0, 0, 1]]", 2},
        {"Example 2: Three provinces", "[[1, 0, 0], [0, 1, 0], [0, 0, 1]]", 3},
        {"Example 3: Two provinces",
         "[[1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 0], [1, 0, 0, 1]]", 2},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix is_connected = t_parse_matrix(tt->is_connected);
        int got = find_provinces(&is_connected);
        t_check_int("find_provinces()", got, tt->want);
        intmatrix_free(&is_connected);
    }
    return t_done();
}
