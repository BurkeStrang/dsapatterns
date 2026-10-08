#include "allpathsforsum.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        int sum;
        const char *want;
    } tests[] = {
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", 10, "[[1, 3, 6]]"},
        {"Example 2", "[12, 7, 1, 9, null, 10, 5]", 23, "[[12, 1, 10]]"},
        {"No path", "[5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1]", 100,
         "[]"},
        {"Empty tree", "[]", 0, "[]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        IntMatrix got = find_paths(root, tt->sum);
        t_check_matrix("find_paths()", &got, tt->want);
        intmatrix_free(&got);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
