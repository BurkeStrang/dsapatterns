#include "maxwidthbinarytree.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        int want;
    } tests[] = {
        {"Example 1: [1,2,3,4,null,null,5]", "[1, 2, 3, 4, null, null, 5]", 4},
        {"Example 2: [1,2,3,4,null,5,6,null,7]",
         "[1, 2, 3, 4, null, 5, 6, null, 7]", 4},
        {"Example 3: [1,2,null,3,4,5]", "[1, 2, null, 3, 4, 5]", 2},
        {"Single node", "[42]", 1},
        {"Empty tree", "[]", 0},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        int got = width_of_binary_tree(root);
        t_check_int("width_of_binary_tree()", got, tt->want);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
