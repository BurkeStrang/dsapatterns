#include "startofcycle.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *vals;
        int vals_len;
        // index the last node links back to, which is also the node we expect
        // back; -1 for no cycle
        int cycle_start;
    } tests[] = {
        {"cycle at node 2", INTS(1, 2, 3, 4), 1},
        {"no cycle", INTS(1, 2, 3), -1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        ListNode *nodes =
            list_from_with_cycle(tt->vals, tt->vals_len, tt->cycle_start);
        ListNode *want = tt->cycle_start == -1 ? NULL : &nodes[tt->cycle_start];
        ListNode *got = find_cycle_start(nodes);
        if (got != want)
        {
            t_errorf("find_cycle_start() = node %d, want node %d",
                     got == NULL ? -1 : got->val,
                     want == NULL ? -1 : want->val);
        }
        free(nodes);
    }
    return t_done();
}
