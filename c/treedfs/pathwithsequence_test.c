#include "pathwithsequence.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        const int *sequence;
        int sequence_len;
        bool want;
    } tests[] = {
        {"Example 1: Path exists", "[1, 7, 9, null, null, 2, 9]", INTS(1, 9, 9),
         true},
        {"Example 2: Path does not exist", "[1, 0, 1, 1, 6, null, 5]",
         INTS(1, 0, 7), false},
        {"Example 3: Empty sequence", "[1, 2]", NO_INTS, false},
        {"Example 4: Empty tree", "[]", INTS(1), false},
        {"Example 5: Single node match", "[5]", INTS(5), true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        bool got = find_path(root, tt->sequence, tt->sequence_len);
        t_check_bool("find_path()", got, tt->want);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
