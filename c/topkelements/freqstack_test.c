#include "freqstack.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        // the numbers to push, then the values every pop should return
        const int *pushes;
        int pushes_len;
        const int *want;
        int want_len;
    } tests[] = {
        {"most frequent first, ties broken by most recent",
         INTS(1, 2, 3, 2, 1, 2, 5), INTS(2, 1, 2, 5, 3, 2, 1)},
        {"all distinct pops like a stack", INTS(4, 7, 9), INTS(9, 7, 4)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        FreqStack stack = freq_stack_new();
        for (int n = 0; n < tt->pushes_len; n++)
        {
            freq_stack_push(&stack, tt->pushes[n]);
        }
        // an unimplemented push leaves nothing to pop
        if (stack.max_heap.len != tt->pushes_len)
        {
            t_errorf("stack holds %d numbers after %d pushes",
                     stack.max_heap.len, tt->pushes_len);
        }
        else
        {
            IntList got = {0};
            for (int n = 0; n < tt->want_len; n++)
            {
                intlist_push(&got, freq_stack_pop(&stack));
            }
            t_check_ints("pops", got.items, got.len, tt->want, tt->want_len);
            intlist_free(&got);
        }
        freq_stack_free(&stack);
    }
    return t_done();
}
