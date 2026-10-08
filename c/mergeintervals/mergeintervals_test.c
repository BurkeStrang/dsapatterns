#include "mergeintervals.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        Interval *intervals;
        int intervals_len;
        const char *want;
    } tests[] = {
        {"Example 1", INTERVALS({1, 4}, {2, 5}, {7, 9}), "[[1, 5], [7, 9]]"},
        {"Example 2", INTERVALS({6, 7}, {2, 4}, {5, 9}), "[[2, 4], [5, 9]]"},
        {"Example 3", INTERVALS({1, 4}, {2, 6}, {3, 5}), "[[1, 6]]"},
        {"No overlap", INTERVALS({1, 2}, {3, 4}, {5, 6}),
         "[[1, 2], [3, 4], [5, 6]]"},
        {"Single interval", INTERVALS({1, 10}), "[[1, 10]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got_len = 0;
        Interval *got = merge(tt->intervals, tt->intervals_len, &got_len);
        t_check_text("merge()", format_intervals(got, got_len), tt->want);
        free(got);
    }
    return t_done();
}
