#include "findeventualstate.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *graph;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1: [3,4,5,6]", "[[1, 2], [2, 3], [2], [], [5], [6], []]",
         INTS(3, 4, 5, 6)},
        {"Example 2: [2,4,5,6]", "[[1, 2], [2, 3], [5], [0], [], [], [4]]",
         INTS(2, 4, 5, 6)},
        {"Example 3: [0,1,2,3,4]", "[[1, 2, 3], [2, 3], [3], [], [0, 1, 2]]",
         INTS(0, 1, 2, 3, 4)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix graph = t_parse_matrix(tt->graph);
        IntList got = eventual_safe_nodes(&graph);
        t_check_ints("eventual_safe_nodes()", got.items, got.len, tt->want,
                     tt->want_len);
        intlist_free(&got);
        intmatrix_free(&graph);
    }
    return t_done();
}
