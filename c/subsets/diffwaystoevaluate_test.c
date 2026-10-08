#include "diffwaystoevaluate.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *input;
        const int *want;
        int want_len;
    } tests[] = {
        {"parentheses addition", "2+3*2", INTS(8, 10)},
        {"parentheses multiple", "2*4-3*5", INTS(-22, 10, -7, 10, 25)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList got = diff_ways_to_evaluate_expression(tt->input);
        t_check_ints("diff_ways_to_evaluate_expression()", got.items, got.len,
                     tt->want, tt->want_len);
        intlist_free(&got);
    }
    return t_done();
}
