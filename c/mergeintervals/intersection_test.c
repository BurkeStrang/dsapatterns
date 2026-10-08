#include "intersection.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        Interval *arr1;
        int arr1_len;
        Interval *arr2;
        int arr2_len;
        const char *want;
    } tests[] = {
        {"Example 1", INTERVALS({1, 3}, {5, 6}, {7, 9}),
         INTERVALS({2, 3}, {5, 7}), "[[2, 3], [5, 6], [7, 7]]"},
        {"Example 2", INTERVALS({1, 3}, {5, 7}, {9, 12}), INTERVALS({5, 10}),
         "[[5, 7], [9, 10]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got_len = 0;
        Interval *got = intersecting_intervals(tt->arr1, tt->arr1_len, tt->arr2,
                                               tt->arr2_len, &got_len);
        t_check_text("intersecting_intervals()", format_intervals(got, got_len),
                     tt->want);
        free(got);
    }
    return t_done();
}
