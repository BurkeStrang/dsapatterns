#include "maxlevelsumbinarytree.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        int want;
    } tests[] = {
        {"Example 1: [1,20,3,4,5,null,8]", "[1, 20, 3, 4, 5, null, 8]", 2},
        {"Example 2: [10,5,-3,3,2,null,11,3,-2,null,1]",
         "[10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]", 3},
        {"Example 3: [5,6,7,8,null,null,9,10]",
         "[5, 6, 7, 8, null, null, 9, 10]", 3},
        {"Single node", "[42]", 1},
        {"Negative values", "[-1, -2, -3]", 1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        int got = max_level_sum(root);
        t_check_int("max_level_sum()", got, tt->want);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
