#include "rearangelist.c"

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
        {"even length list", INTS(1, 2, 3, 4), INTS(1, 4, 2, 3)},
        {"odd length list", INTS(1, 2, 3), INTS(1, 3, 2)},
        {"single node", INTS(1), INTS(1)},
        {"empty list", NO_INTS, NO_INTS},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        ListNode *nodes = list_from(tt->head, tt->head_len);
        ListNode *got = rearange_list(nodes);
        IntList got_values = list_values(got);
        t_check_ints("rearange_list()", got_values.items, got_values.len,
                     tt->want, tt->want_len);
        intlist_free(&got_values);
        free(nodes);
    }
    return t_done();
}
