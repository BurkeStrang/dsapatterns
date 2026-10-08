#include "reversesublist.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *head;
        int head_len;
        int p;
        int q;
        const int *want;
        int want_len;
    } tests[] = {
        {"reverse middle sublist", INTS(1, 2, 3, 4, 5), 2, 4,
         INTS(1, 4, 3, 2, 5)},
        {"reverse entire list", INTS(1, 2, 3), 1, 3, INTS(3, 2, 1)},
        {"reverse single node (no change)", INTS(1, 2), 2, 2, INTS(1, 2)},
        {"reverse head only", INTS(1, 2), 1, 1, INTS(1, 2)},
        {"reverse tail only", INTS(1, 2), 2, 2, INTS(1, 2)},
        {"empty list", NO_INTS, 1, 1, NO_INTS},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        ListNode *nodes = list_from(tt->head, tt->head_len);
        ListNode *got = reverse_sub(nodes, tt->p, tt->q);
        IntList got_values = list_values(got);
        t_check_ints("reverse_sub()", got_values.items, got_values.len,
                     tt->want, tt->want_len);
        intlist_free(&got_values);
        free(nodes);
    }
    return t_done();
}
