#include "zigzagtraversal.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        const char *want;
    } tests[] = {
        {"Example 1: [1,2,3,4,5,null,6]", "[1, 2, 3, 4, 5, null, 6]",
         "[[1], [3, 2], [4, 5, 6]]"},
        {"Example 2: [7,4,8,2,5,null,9,null,3]",
         "[7, 4, 8, 2, 5, null, 9, null, 3]", "[[7], [8, 4], [2, 5, 9], [3]]"},
        {"Single node", "[42]", "[[42]]"},
        {"Empty tree", "[]", "[]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        IntMatrix got = traverse_zig_zag(root);
        t_check_matrix("traverse_zig_zag()", &got, tt->want);
        intmatrix_free(&got);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
