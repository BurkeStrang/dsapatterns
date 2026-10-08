#include "sumofelements.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *nums;
        int nums_len;
        int k1;
        int k2;
        int want;
    } tests[] = {
        {"basic test", INTS(1, 3, 12, 5, 15, 11), 3, 6, 23},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = find_sum_of_elements(tt->nums, tt->nums_len, tt->k1, tt->k2);
        t_check_int("find_sum_of_elements()", got, tt->want);
    }
    return t_done();
}
