#include "minnumreachallnodes.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int n;
        const char *edges;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", 6, "[[0, 1], [0, 2], [2, 5], [3, 4], [4, 2]]",
         INTS(0, 3)},
        {"Single node", 1, "[]", INTS(0)},
        {"Disconnected nodes", 3, "[]", INTS(0, 1, 2)},
        {"All nodes connected in a chain", 4, "[[0, 1], [1, 2], [2, 3]]",
         INTS(0)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix edges = t_parse_matrix(tt->edges);
        IntList got = find_smallest_set_of_vertices(tt->n, &edges);
        t_check_ints("find_smallest_set_of_vertices()", got.items, got.len,
                     tt->want, tt->want_len);
        intlist_free(&got);
        intmatrix_free(&edges);
    }
    return t_done();
}
