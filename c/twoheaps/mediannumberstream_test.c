#include "mediannumberstream.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        // the numbers to insert, and the expected median after each insert
        const int *nums;
        int nums_len;
        const double *expected;
        int expected_len;
    } tests[] = {
        {"ordered", INTS(1, 2, 3, 4, 5), DOUBLES(1.0, 1.5, 2.0, 2.5, 3.0)},
        {"unordered", INTS(5, 3, 8, 1, 2), DOUBLES(5, 4, 5, 4, 3)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        Median median = median_new();
        for (int n = 0; n < tt->nums_len; n++)
        {
            insert_num(&median, tt->nums[n]);
            // an unimplemented insert_num leaves nothing to take a median of
            if (median.max_heap.len == 0)
            {
                t_errorf("after inserting %d the stream is still empty",
                         tt->nums[n]);
                break;
            }
            double got = find_median(&median);
            if (got != tt->expected[n])
            {
                t_errorf("after inserting %d, expected median %.1f, got %.1f",
                         tt->nums[n], tt->expected[n], got);
            }
        }
        median_free(&median);
    }
    return t_done();
}
