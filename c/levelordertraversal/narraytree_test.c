#include "narraytree.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        // level order, with null ending each group of children
        const char *tree;
        const char *want;
    } tests[] = {
        {"Example 1: [1,null,2,3,4,null,5,6]", "[1, null, 2, 3, 4, null, 5, 6]",
         "[[1], [2, 3, 4], [5, 6]]"},
        {"Single node", "[42]", "[[42]]"},
        {"Empty tree", "[]", "[]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        NAryTree tree = nary_tree_from(vals.items, vals.len);
        IntMatrix got = level_order(tree.root);
        t_check_matrix("level_order()", &got, tt->want);
        intmatrix_free(&got);
        nary_tree_free(&tree);
        intlist_free(&vals);
    }
    return t_done();
}
