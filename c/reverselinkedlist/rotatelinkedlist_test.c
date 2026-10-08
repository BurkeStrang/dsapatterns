#include "rotatelinkedlist.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *head;
        int head_len;
        int rotations;
        const int *want;
        int want_len;
    } tests[] = {
        {"rotate by 2", INTS(1, 2, 3, 4, 5), 2, INTS(4, 5, 1, 2, 3)},
        {"rotate by 0 (no change)", INTS(1, 2, 3), 0, INTS(1, 2, 3)},
        {"rotate by length (no change)", INTS(1, 2, 3), 3, INTS(1, 2, 3)},
        {"rotate by more than length", INTS(1, 2, 3), 5, INTS(2, 3, 1)},
        {"single node", INTS(1), 1, INTS(1)},
        {"empty list", NO_INTS, 3, NO_INTS},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        ListNode *nodes = list_from(tt->head, tt->head_len);
        ListNode *got = rotate(nodes, tt->rotations);
        IntList got_values = list_values(got);
        t_check_ints("rotate()", got_values.items, got_values.len, tt->want,
                     tt->want_len);
        intlist_free(&got_values);
        free(nodes);
    }
    return t_done();
}
