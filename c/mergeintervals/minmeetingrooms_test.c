#include "minmeetingrooms.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        Meeting meetings[4];
        int meetings_len;
        int want;
    } tests[] = {
        {"Example 1: overlapping meetings", {{1, 4}, {2, 5}, {7, 9}}, 3, 2},
        {"Example 2: non-overlapping meetings",
         {{6, 7}, {2, 4}, {8, 12}},
         3,
         1},
        {"Example 3: overlapping meetings", {{1, 4}, {2, 3}, {3, 6}}, 3, 2},
        {"Example 4: complex overlaps", {{4, 5}, {2, 3}, {2, 4}, {3, 5}}, 4, 2},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        Meeting meetings[4];
        // the function sorts its input, so give it a copy
        memcpy(meetings, tt->meetings, sizeof(meetings));
        int got = find_minimum_meeting_rooms(meetings, tt->meetings_len);
        t_check_int("find_minimum_meeting_rooms()", got, tt->want);
    }
    return t_done();
}
