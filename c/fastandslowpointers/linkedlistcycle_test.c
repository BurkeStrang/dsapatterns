#include "linkedlistcycle.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *vals;
        int vals_len;
        int cycle_start; // index the last node links back to, or -1
        bool want;
    } tests[] = {
        {"no cycle", INTS(1, 2, 3), -1, false},
        {"cycle exists", INTS(1, 2, 3), 0, true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        ListNode *nodes =
            list_from_with_cycle(tt->vals, tt->vals_len, tt->cycle_start);
        bool got = has_cycle(nodes);
        t_check_bool("has_cycle()", got, tt->want);
        free(nodes);
    }
    return t_done();
}
