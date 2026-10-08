#include "findlargestvalueinrow.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", "[1, 2, 3, 4, 5, null, 6]", INTS(1, 3, 6)},
        {"Example 2", "[7, 4, 8, 2, 5, null, 9, null, 3]", INTS(7, 8, 9, 3)},
        {"Example 3", "[10, 5]", INTS(10, 5)},
        {"Empty tree", "[]", NO_INTS},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        IntList got = largest_values(root);
        t_check_ints("largest_values()", got.items, got.len, tt->want,
                     tt->want_len);
        intlist_free(&got);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
