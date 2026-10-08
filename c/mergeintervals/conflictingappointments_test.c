#include "conflictingappointments.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        Interval *intervals;
        int intervals_len;
        bool want;
    } tests[] = {
        {"Example 1: overlapping intervals", INTERVALS({1, 4}, {2, 5}, {7, 9}),
         false},
        {"Example 2: non-overlapping intervals",
         INTERVALS({6, 7}, {2, 4}, {13, 14}, {8, 12}, {45, 47}), true},
        {"Example 3: overlapping intervals", INTERVALS({4, 5}, {2, 3}, {3, 6}),
         false},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        bool got =
            can_attend_all_appointments(tt->intervals, tt->intervals_len);
        t_check_bool("can_attend_all_appointments()", got, tt->want);
    }
    return t_done();
}
