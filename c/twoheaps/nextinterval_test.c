#include "nextinterval.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        Interval intervals[3];
        int intervals_len;
        const int *want;
        int want_len;
    } tests[] = {
        {"basic non-overlapping", {{2, 3}, {3, 4}, {5, 6}}, 3, INTS(1, 2, -1)},
        {"overlapping intervals", {{3, 4}, {1, 5}, {4, 6}}, 3, INTS(2, -1, -1)},
        {"single interval", {{1, 2}}, 1, INTS(-1)},
        {"self as next interval", {{1, 1}, {3, 4}}, 2, INTS(0, -1)},
        {"no next interval for identical",
         {{1, 2}, {1, 2}, {1, 2}},
         3,
         INTS(-1, -1, -1)},
        {"start equals end", {{1, 2}, {2, 3}, {3, 4}}, 3, INTS(1, 2, -1)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int *got = find_next_interval(tt->intervals, tt->intervals_len);
        t_check_ints("find_next_interval()", got, tt->intervals_len, tt->want,
                     tt->want_len);
        free(got);
    }
    return t_done();
}
