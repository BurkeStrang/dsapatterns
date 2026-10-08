#include "rightviewbinarytree.c"

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
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", INTS(1, 3, 7)},
        {"Example 2", "[12, 7, 1, null, 9, 10, 5, null, 3]", INTS(12, 1, 5, 3)},
        {"Example 3", "[8, 4, 9, 3, null, null, 10, 2]", INTS(8, 9, 10, 2)},
        {"Empty tree", "[]", NO_INTS},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        IntList got = right_view(root);
        t_check_ints("right_view()", got.items, got.len, tt->want,
                     tt->want_len);
        intlist_free(&got);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
