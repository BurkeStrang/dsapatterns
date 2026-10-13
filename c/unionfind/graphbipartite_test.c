#include "graphbipartite.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *graph;
        bool want;
    } tests[] = {
        {"Example 1", "[[1, 3], [0, 2], [1, 3], [0, 2]]", true},
        {"Example 2", "[[1], [0], [3], [2]]", true},
        {"Example 3", "[[1, 2, 3], [0, 2], [0, 1, 3], [0, 2]]", false},
        {"No edges", "[[], [], []]", true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix graph = t_parse_matrix(tt->graph);
        bool got = is_bipartite(&graph);
        t_check_bool("is_bipartite()", got, tt->want);
        intmatrix_free(&graph);
    }
    return t_done();
}
