#include "redundantconnection.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *edges;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", "[[1, 2], [1, 3], [3, 4], [1, 4], [1, 5]]", INTS(1, 4)},
        {"Example 2", "[[1, 2], [2, 3], [3, 1], [3, 4]]", INTS(3, 1)},
        {"Example 3", "[[1, 2], [2, 3], [3, 4], [4, 2], [5, 6]]", INTS(4, 2)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix edges = t_parse_matrix(tt->edges);
        IntList got = find_redundant_connection(&edges);
        t_check_ints("find_redundant_connection()", got.items, got.len,
                     tt->want, tt->want_len);
        intlist_free(&got);
        intmatrix_free(&edges);
    }
    return t_done();
}
