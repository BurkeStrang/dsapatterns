#include "avg.c"

#include "slidingwindow/shared.h"
#include "testing/testing.h"

int main(void)
{
    struct
    {
        const char *name; // description of this test case
        // Named input parameters for target function.
        int k;
        const int *arr;
        int arr_len;
        const double *want;
        int want_len;
    } tests[] = {
        {"basic case", 5, INTS(1, 3, 2, 6, -1, 4, 1, 8, 2),
         DOUBLES(2.2, 2.8, 2.4, 3.6, 2.8)},
        {"window size 1", 1, INTS(5, 10, 15), DOUBLES(5.0, 10.0, 15.0)},
        {"window size equals array length", 4, INTS(2, 4, 6, 8), DOUBLES(5.0)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        t_run(tests[i].name);
        int got_len = 0;
        double *got =
            find_averages(tests[i].k, tests[i].arr, tests[i].arr_len, &got_len);
        if (!equal_doubles(got, got_len, tests[i].want, tests[i].want_len))
        {
            t_errorf("find_averages() = %s, want %s",
                     t_format_doubles(got, got_len),
                     t_format_doubles(tests[i].want, tests[i].want_len));
        }
        free(got);
    }
    return t_done();
}
