#include "reversealtksublist.c"

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
        {"reverse every alternate 2 nodes", INTS(1, 2, 3, 4, 5, 6), 2,
         INTS(2, 1, 3, 4, 6, 5)},
        {"reverse every alternate 3 nodes", INTS(1, 2, 3, 4, 5, 6, 7), 3,
         INTS(3, 2, 1, 4, 5, 6, 7)},
        {"k greater than length", INTS(1, 2), 5, INTS(2, 1)},
        {"single node", INTS(1), 2, INTS(1)},
        {"empty list", NO_INTS, 2, NO_INTS},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        ListNode *nodes = list_from(tt->head, tt->head_len);
        ListNode *got = reverse_alt(nodes, tt->k);
        IntList got_values = list_values(got);
        t_check_ints("reverse_alt()", got_values.items, got_values.len,
                     tt->want, tt->want_len);
        intlist_free(&got_values);
        free(nodes);
    }
    return t_done();
}
