#include "levelordersuccesor.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        int key;
        int want; // compared by value, with 0 meaning no successor
    } tests[] = {
        {"Example 1", "[1, 2, 3, 4, 5]", 3, 4},
        {"Example 2", "[12, 7, 1, 9, null, 10, 5]", 9, 10},
        {"Example 3", "[12, 7, 1, 9, null, 10, 5]", 12, 7},
        {"No successor (last node)", "[1, 2]", 2, 0},
        {"Empty tree", "[]", 1, 0},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        TreeNode *got = find_successor(root, tt->key);
        t_check_int("find_successor()", got == NULL ? 0 : got->val, tt->want);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
