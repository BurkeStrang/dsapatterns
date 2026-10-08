#include "evenoddtree.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        bool want;
    } tests[] = {
        {"Example 1: Valid Even-Odd Tree", "[1, 10, 4, 3, 7]", true},
        {"Example 2: Invalid Even-Odd Tree (odd values at level 1)",
         "[5, 9, 3, 12, null, null, 8]", false},
        {"Example 3: Invalid Even-Odd Tree (even values at even level)",
         "[7, 10, 2, 12, 8]", false},
        {"Single node (odd value at level 0)", "[1]", true},
        {"Single node (even value at level 0)", "[2]", false},
        {"Empty tree", "[]", true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        bool got = is_even_odd_tree(root);
        t_check_bool("is_even_odd_tree()", got, tt->want);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
