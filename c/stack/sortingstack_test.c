#include "sortingstack.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        // stacks are written with the bottom element first and the top last
        const int *input;
        int input_len;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", INTS(34, 3, 31, 98, 92, 23), INTS(3, 23, 31, 34, 92, 98)},
        {"Example 2", INTS(4, 3, 2, 10, 12, 1, 5, 6),
         INTS(1, 2, 3, 4, 5, 6, 10, 12)},
        {"Example 3", INTS(20, 10, -5, -1), INTS(-5, -1, 10, 20)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList input = intlist_from(tt->input, tt->input_len);
        IntList got = sort_stack(&input);
        t_check_ints("sort_stack()", got.items, got.len, tt->want,
                     tt->want_len);
        intlist_free(&got);
        intlist_free(&input);
    }
    return t_done();
}
