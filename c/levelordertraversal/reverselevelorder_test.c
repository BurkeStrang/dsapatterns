#include "reverselevelorder.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        const char *want;
    } tests[] = {
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", "[[4, 5, 6, 7], [2, 3], [1]]"},
        {"Example 2", "[12, 7, 1, null, 9, 10, 5]",
         "[[9, 10, 5], [7, 1], [12]]"},
        {"Example 3", "[6, 5, 2, null, null, 1, 6, 3, 56, null, 3]",
         "[[3, 56, 3], [1, 6], [5, 2], [6]]"},
        {"Empty tree", "[]", "[]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        IntMatrix got = traverse(root);
        t_check_matrix("traverse()", &got, tt->want);
        intmatrix_free(&got);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
