#include "minlevel.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        int want;
    } tests[] = {
        {"Example 1", "[1, 2, 3, 4, 5]", 2},
        {"Example 2", "[1, 2]", 2},
        {"Example 3", "[1, 2, 3, 4, 5, 6]", 3},
        {"Example 4", "[1]", 1},
        {"Empty tree", "[]", 0},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        int got = find_depth(root);
        t_check_int("find_depth()", got, tt->want);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
