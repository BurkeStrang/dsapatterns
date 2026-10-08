#include "uniquebst.c"

#include "common/queue.h"
#include "testing/testing.h"

// level_order writes a tree in level order, with null for a missing child
// and trailing nulls left off.
static const char *level_order
(
    TreeNode *root
)
{
    char *buffer = t_format_buffer();
    Queue queue = queue_new(sizeof(TreeNode *));
    queue_push(&queue, &root);
    int pending_nulls = 0; // nulls are only written once a value follows
    bool first = true;
    t_format_append(buffer, "[");
    while (queue.len > 0)
    {
        TreeNode *node;
        queue_pop(&queue, &node);
        if (node == NULL)
        {
            pending_nulls++;
            continue;
        }
        char item[32];
        for (; pending_nulls > 0; pending_nulls--)
        {
            t_format_append(buffer, ", null");
        }
        snprintf(item, sizeof(item), first ? "%d" : ", %d", node->val);
        t_format_append(buffer, item);
        first = false;
        queue_push(&queue, &node->left);
        queue_push(&queue, &node->right);
    }
    t_format_append(buffer, "]");
    queue_free(&queue);
    return buffer;
}

int main(void)
{
    struct test
    {
        const char *name;
        int n;
        // each expected tree in level order, with null for a missing child
        const char *const *want;
        int want_len;
    } tests[] = {
        {"Example 1", 2, STRS("[1, null, 2]", "[2, 1]")},
        {"Example 2", 3,
         STRS("[1, null, 2, null, 3]", "[1, null, 3, 2]", "[2, 1, 3]",
              "[3, 1, null, null, 2]", "[3, 2, null, 1]")},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        UniqueTrees got = find_unique_trees(tt->n);
        t_check_int("number of trees", got.trees.len, tt->want_len);
        for (int n = 0; n < got.trees.len && n < tt->want_len; n++)
        {
            t_check_text("tree", level_order(got.trees.items[n]), tt->want[n]);
        }
        unique_trees_free(&got);
    }
    return t_done();
}
