#include "squareasortedarray.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *input;
        int input_len;
        const int *expected;
        int expected_len;
    } tests[] = {
        {"case 1", INTS(-2, -1, 0, 2, 3), INTS(0, 1, 4, 4, 9)},
        {"case 2", INTS(-3, -1, 0, 1, 2), INTS(0, 1, 1, 4, 9)},
        {"case 3", INTS(0), INTS(0)},
        {"case 4", INTS(-1), INTS(1)},
        {"case 5", INTS(1, 2, 3), INTS(1, 4, 9)},
        {"case 6", INTS(-4, -3, -2, -1), INTS(1, 4, 9, 16)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int *result = make_squares(tt->input, tt->input_len);
        t_check_ints("make_squares()", result, tt->input_len, tt->expected,
                     tt->expected_len);
        free(result);
    }
    return t_done();
}
