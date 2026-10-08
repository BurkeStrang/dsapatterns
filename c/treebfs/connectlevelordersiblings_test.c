#include "connectlevelordersiblings.c"

#include "testing/testing.h"

// level_order_next traverses the tree using next pointers and returns values
// level by level.
static IntMatrix level_order_next
(
    TreeNode *root
)
{
    IntMatrix result = {0};
    while (root != NULL)
    {
        IntList level = {0};
        TreeNode *next_level = NULL;
        for (TreeNode *curr = root; curr != NULL; curr = curr->next)
        {
            intlist_push(&level, curr->val);
            if (next_level == NULL)
            {
                next_level = curr->left != NULL ? curr->left : curr->right;
            }
        }
        intmatrix_push(&result, level);
        root = next_level;
    }
    return result;
}

int main(void)
{
    struct test
    {
        const char *name;
        const char *tree; // level order, with null for a missing child
        // expected level order traversal using next pointers
        const char *want;
    } tests[] = {
        {"Example 1", "[1, 2, 3, 4, 5, 6, 7]", "[[1], [2, 3], [4, 5, 6, 7]]"},
        {"Example 2", "[12, 7, 1, 9, null, 10, 5]",
         "[[12], [7, 1], [9, 10, 5]]"},
        {"Empty tree", "[]", "[]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList vals = t_parse_ints_with_null(tt->tree, TREE_NULL);
        TreeNode *root = tree_from(vals.items, vals.len);
        TreeNode *got_root = connect(root);
        IntMatrix got = level_order_next(got_root);
        t_check_matrix("connect()", &got, tt->want);
        intmatrix_free(&got);
        free(root);
        intlist_free(&vals);
    }
    return t_done();
}
