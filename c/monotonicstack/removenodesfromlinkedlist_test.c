#include "removenodesfromlinkedlist.c"

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
        {"Example 1", INTS(5, 3, 7, 4, 2, 1), INTS(7, 4, 2, 1)},
        {"Example 2", INTS(1, 2, 3, 4, 5), INTS(5)},
        {"Example 3", INTS(5, 4, 3, 2, 1), INTS(5, 4, 3, 2, 1)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        ListNode *nodes = list_from(tt->head, tt->head_len);
        ListNode *got = remove_nodes(nodes);
        IntList got_values = list_values(got);
        t_check_ints("remove_nodes()", got_values.items, got_values.len,
                     tt->want, tt->want_len);
        intlist_free(&got_values);
        free(nodes);
    }
    return t_done();
}
