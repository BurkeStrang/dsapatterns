#include "topsort.c"

#include "topologicalsort/shared.h"
#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int vertices;
        const char *edges;
        // one valid order (there can be several), or empty when there is none
        const int *want;
        int want_len;
    } tests[] = {
        {"Test Case 1", 6, "[[5, 2], [5, 0], [4, 0], [4, 1], [2, 3], [3, 1]]",
         INTS(5, 4, 2, 3, 1, 0)},
        {"Test Case 2", 4, "[[0, 1], [1, 2], [2, 3]]", INTS(0, 1, 2, 3)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix edges = t_parse_matrix(tt->edges);
        IntList got = sort(tt->vertices, &edges);
        bool ok = tt->want_len == 0
                      ? got.len == 0
                      : is_topological_order(&got, tt->vertices, &edges);
        if (!ok)
        {
            t_errorf("sort() = %s, want something like %s",
                     t_format_ints(got.items, got.len),
                     t_format_ints(tt->want, tt->want_len));
        }
        intlist_free(&got);
        intmatrix_free(&edges);
    }
    return t_done();
}
