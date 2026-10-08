#include "findnonduplicates.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int *input;
        int input_len;
        const int *expected;
        int expected_len;
        int length;
    } tests[] = {
        {"case 1", INTS(2, 3, 3, 3, 6, 9, 9), INTS(2, 3, 6, 9), 4},
        {"case 2", INTS(2, 2, 2, 11), INTS(2, 11), 2},
        {"case 3", INTS(1, 2, 2), INTS(1, 2), 2},
        {"case 4", INTS(0, 0, 1, 1, 1, 2, 2, 3, 3, 4), INTS(0, 1, 2, 3, 4), 5},
        {"case 5", INTS(1), INTS(1), 1},
        {"case 6", INTS(1, 2, 3), INTS(1, 2, 3), 3},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = move_elements(tt->input, tt->input_len);
        t_check_int("move_elements() length", got, tt->length);
        if (got == tt->length)
        {
            t_check_ints("move_elements() array", tt->input, got, tt->expected,
                         tt->expected_len);
        }
    }
    return t_done();
}
