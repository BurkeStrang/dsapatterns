#include "hassumpath.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        int sum;
        bool want;
    } tests[] = {
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", 10, true},
        {"Example 2", "[12, 7, 1, 9, null, 10, 5]", 23, true},
        {"Example 3", "[12, 7, 1, 9, null, 10, 5]", 16, false},
        {"Empty tree", "[]", 0, false},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        bool got = has_path(root, tt->sum);
        t_check_bool("has_path()", got, tt->want);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
