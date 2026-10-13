#include "minheighttrees.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int nodes;
        const char *edges;
        // the roots, sorted; they can come back in any order
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", 5, "[[0, 1], [1, 2], [1, 3], [2, 4]]", INTS(1, 2)},
        {"Example 2", 4, "[[0, 1], [0, 2], [2, 3]]", INTS(0, 2)},
        {"Example 3", 4, "[[0, 1], [1, 2], [1, 3]]", INTS(1)},
        {"Star", 4, "[[1, 0], [1, 2], [1, 3]]", INTS(1)},
        {"Two centres", 6, "[[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]",
         INTS(3, 4)},
        {"One node", 1, "[]", INTS(0)},
        {"No nodes", 0, "[]", NO_INTS},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix edges = t_parse_matrix(tt->edges);
        IntList got = find_trees(tt->nodes, &edges);
        t_sort_ints(got.items, got.len);
        t_check_ints("find_trees()", got.items, got.len, tt->want,
                     tt->want_len);
        intlist_free(&got);
        intmatrix_free(&edges);
    }
    return t_done();
}
