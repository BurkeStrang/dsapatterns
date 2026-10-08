#include "slidingwindowmedian.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *nums;
        int nums_len;
        int k;
        const double *expected;
        int expected_len;
    } tests[] = {
        {"k=2", INTS(1, 2, -1, 3, 5), 2, DOUBLES(1.5, 0.5, 1.0, 4.0)},
        {"k=3", INTS(1, 2, -1, 3, 5), 3, DOUBLES(1.0, 2.0, 3.0)},
        {"single element window", INTS(4, 1, 3), 1, DOUBLES(4.0, 1.0, 3.0)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        double *result =
            find_sliding_window_median(tt->nums, tt->nums_len, tt->k);
        bool same = result != NULL;
        for (int n = 0; same && n < tt->expected_len; n++)
        {
            same = result[n] == tt->expected[n];
        }
        if (!same)
        {
            t_errorf("find_sliding_window_median() = %s, expected %s",
                     t_format_doubles(result, tt->expected_len),
                     t_format_doubles(tt->expected, tt->expected_len));
        }
        free(result);
    }
    return t_done();
}
