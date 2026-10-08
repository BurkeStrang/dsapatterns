#include "reverseksublist.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *head;
        int head_len;
        int k;
        const int *want;
        int want_len;
    } tests[] = {
        {"reverse every 2 nodes", INTS(1, 2, 3, 4, 5), 2, INTS(2, 1, 4, 3, 5)},
        {"reverse every 3 nodes", INTS(1, 2, 3, 4, 5), 3, INTS(3, 2, 1, 5, 4)},
        {"k greater than length", INTS(1, 2), 5, INTS(2, 1)},
        {"single node", INTS(1), 2, INTS(1)},
        {"empty list", NO_INTS, 2, NO_INTS},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        ListNode *nodes = list_from(tt->head, tt->head_len);
        ListNode *got = reverse_k_sub(nodes, tt->k);
        IntList got_values = list_values(got);
        t_check_ints("reverse_k_sub()", got_values.items, got_values.len,
                     tt->want, tt->want_len);
        intlist_free(&got_values);
        free(nodes);
    }
    return t_done();
}
