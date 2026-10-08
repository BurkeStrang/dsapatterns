#include "mergeksortedlist.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *lists; // one list per row
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", "[[2, 6, 8], [3, 6, 7], [1, 3, 4]]",
         INTS(1, 2, 3, 3, 4, 6, 6, 7, 8)},
        {"Example 2", "[[5, 8, 9], [1, 7]]", INTS(1, 5, 7, 8, 9)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix values = t_parse_matrix(tt->lists);
        // each list is built in its own block of nodes, freed at the end
        ListNode **lists = malloc((size_t)values.len * sizeof(ListNode *));
        ListNode **blocks = malloc((size_t)values.len * sizeof(ListNode *));
        for (int l = 0; l < values.len; l++)
        {
            const IntList *row = &values.rows[l];
            ListNode *nodes = malloc((size_t)row->len * sizeof(ListNode));
            for (int n = 0; n < row->len; n++)
            {
                nodes[n].val = row->items[n];
                nodes[n].next = n + 1 < row->len ? &nodes[n + 1] : NULL;
            }
            lists[l] = nodes;
            blocks[l] = nodes;
        }
        ListNode *merged = merge(lists, values.len);
        IntList got = {0};
        for (ListNode *node = merged; node != NULL; node = node->next)
        {
            intlist_push(&got, node->val);
        }
        t_check_ints("merge()", got.items, got.len, tt->want, tt->want_len);
        intlist_free(&got);
        for (int l = 0; l < values.len; l++)
        {
            free(blocks[l]);
        }
        free(blocks);
        free(lists);
        intmatrix_free(&values);
    }
    return t_done();
}
