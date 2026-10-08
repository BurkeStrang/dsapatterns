#include "findmiddle.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *head;
        int head_len;
        int want; // value of the middle node, or -1 for an empty list
    } tests[] = {
        {"odd length list", INTS(1, 2, 3, 4, 5), 3},
        {"even length list", INTS(1, 2, 3, 4), 3},
        {"single node", INTS(1), 1},
        {"two nodes", INTS(1, 2), 2},
        {"nil list", NO_INTS, -1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        ListNode *nodes = list_from(tt->head, tt->head_len);
        ListNode *got = find_middle(nodes);
        t_check_int("find_middle()", got == NULL ? -1 : got->val, tt->want);
        free(nodes);
    }
    return t_done();
}
