#include "findcyclelength.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *vals;
        int vals_len;
        int cycle_start; // index the last node links back to, or -1
        int want;
    } tests[] = {
        // cycle starts at the second node, length 3
        {"cycle of length 3", INTS(1, 2, 3, 4), 1, 3},
        {"no cycle", INTS(1, 2, 3), -1, 0},
        {"cycle of length 1 (self loop)", INTS(1), 0, 1},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        ListNode *nodes =
            list_from_with_cycle(tt->vals, tt->vals_len, tt->cycle_start);
        int got = find_cycle_length(nodes);
        t_check_int("find_cycle_length()", got, tt->want);
        free(nodes);
    }
    return t_done();
}
