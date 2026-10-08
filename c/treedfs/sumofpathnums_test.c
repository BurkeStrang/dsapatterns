#include "sumofpathnums.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        int want;
    } tests[] = {
        {"Example 1", "[1, 2, 3]", 25}, // Paths: 12, 13 => 12+13=25
        // Paths: 101, 106, 115 => 101+106+115=322
        //                       1
        //                     /   \
        //                    0     1
        //                   / \     \
        //                  1   6     5
        {"Example 2", "[1, 0, 1, 1, 6, null, 5]", 322},
        {"Single node", "[5]", 5},
        {"Empty tree", "[]", 0},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        int got = find_sum_of_path_numbers(root);
        t_check_int("find_sum_of_path_numbers()", got, tt->want);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
