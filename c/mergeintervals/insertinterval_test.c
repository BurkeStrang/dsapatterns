#include "insertinterval.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        Interval *intervals;
        int intervals_len;
        Interval new_interval;
        const char *want;
    } tests[] = {
        {"Example 1",
         INTERVALS({1, 3}, {5, 7}, {8, 12}),
         {4, 6},
         "[[1, 3], [4, 7], [8, 12]]"},
        {"Example 2",
         INTERVALS({1, 3}, {5, 7}, {8, 12}),
         {4, 10},
         "[[1, 3], [4, 12]]"},
        {"Example 3", INTERVALS({2, 3}, {5, 7}), {1, 4}, "[[1, 4], [5, 7]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got_len = 0;
        Interval *got = insert(tt->intervals, tt->intervals_len,
                               tt->new_interval, &got_len);
        t_check_text("insert()", format_intervals(got, got_len), tt->want);
        free(got);
    }
    return t_done();
}
