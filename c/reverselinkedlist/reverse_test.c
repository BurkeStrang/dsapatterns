#include "reverse.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *head;
        int head_len;
        const int *want;
        int want_len;
    } tests[] = {
        {"multiple nodes", INTS(1, 2, 3), INTS(3, 2, 1)},
        {"single node", INTS(1), INTS(1)},
        {"empty list", NO_INTS, NO_INTS},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        ListNode *nodes = list_from(tt->head, tt->head_len);
        ListNode *got = reverse(nodes);
        IntList got_values = list_values(got);
        t_check_ints("reverse()", got_values.items, got_values.len, tt->want,
                     tt->want_len);
        intlist_free(&got_values);
        free(nodes);
    }
    return t_done();
}
