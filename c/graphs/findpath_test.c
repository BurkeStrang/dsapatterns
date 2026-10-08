#include "findpath.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int n;
        const char *edges;
        int start;
        int end;
        bool want;
    } tests[] = {
        {"path exists simple", 4, "[[0, 1], [1, 2], [2, 3]]", 0, 3, true},
        {"no path between disconnected components", 4, "[[0, 1], [2, 3]]", 0, 3,
         false},
        {"no path with isolated nodes", 5, "[[0, 1], [3, 4]]", 0, 4, false},
        {"single node graph", 1, "[]", 0, 0, true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix edges = t_parse_matrix(tt->edges);
        bool got = valid_path(tt->n, &edges, tt->start, tt->end);
        t_check_bool("valid_path()", got, tt->want);
        intmatrix_free(&edges);
    }
    return t_done();
}
