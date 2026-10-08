#include "connectalllevelordersibs.c"

#include "testing/testing.h"

// flatten_next traverses the tree using next pointers and returns values in
// order.
static IntList flatten_next
(
    const TreeNode *root
)
{
    IntList result = {0};
    for (const TreeNode *curr = root; curr != NULL; curr = curr->next)
    {
        intlist_push(&result, curr->val);
    }
    return result;
}

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", INTS(1, 2, 3, 4, 5, 6, 7)},
        {"Example 2", "[12, 7, 1, 9, null, 10, 5]", INTS(12, 7, 1, 9, 10, 5)},
        {"Empty tree", "[]", NO_INTS},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        TreeNode *got_root = connect_all(root);
        IntList got = flatten_next(got_root);
        t_check_ints("connect_all()", got.items, got.len, tt->want,
                     tt->want_len);
        intlist_free(&got);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
