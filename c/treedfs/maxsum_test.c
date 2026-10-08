#include "maxsum.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        int want;
    } tests[] = {
        {"simple tree", "[1, 2, 3]", 6}, // 2 + 1 + 3
        // 15 + 20 + 7
        {"tree with negative values", "[-10, 9, 20, null, null, 15, 7]", 42},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        int got = find_maximum_path_sum(root);
        t_check_int("find_maximum_path_sum()", got, tt->want);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
