#include "countpathssum.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        int target_sum;
        int want;
    } tests[] = {
        // Paths: [1,2], [3]
        {"Example 1: Single path", "[1, 2, 3]", 3, 2},
        // Paths: [5,3], [5,2,1], [10,-3,11]
        {"Example 2: Multiple paths",
         "[10, 5, -3, 3, 2, null, 11, 3, -2, null, 1]", 8, 3},
        {"Example 3: No path", "[1, 2]", 100, 0},
        {"Example 4: Empty tree", "[]", 0, 0},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        int got = count_paths(root, tt->target_sum);
        t_check_int("count_paths()", got, tt->want);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
