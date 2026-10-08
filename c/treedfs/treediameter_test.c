#include "treediameter.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        int want;
    } tests[] = {
        {"Single node", "[1]", 0},
        // Path: 4-2-1-3 or 5-2-1-3
        //            1
        //           / \
        //          2   3
        //         / \
        //        4   5
        {"Simple tree", "[1, 2, 3, 4, 5]", 4},
        // Path: 4-1-2-3
        //       1
        //      / \
        //     4   2
        //         \
        //          3
        {"Linear tree", "[1, 4, 2, null, null, null, 3]", 4},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        int got = find_diameter(root);
        t_check_int("find_diameter()", got, tt->want);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
