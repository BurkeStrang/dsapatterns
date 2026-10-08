#include "dutchnationalflag.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int *in;
        int in_len;
        const int *want;
        int want_len;
    } tests[] = {
        {"example1", INTS(1, 0, 2, 1, 0), INTS(0, 0, 1, 1, 2)},
        {"example2", INTS(2, 2, 0, 1, 2, 0), INTS(0, 0, 1, 2, 2, 2)},
        {"all zeros", INTS(0, 0, 0), INTS(0, 0, 0)},
        {"all twos", INTS(2, 2, 2), INTS(2, 2, 2)},
        {"already sorted", INTS(0, 0, 1, 1, 2, 2), INTS(0, 0, 1, 1, 2, 2)},
        {"single element", INTS(1), INTS(1)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int *got = dutch(tt->in, tt->in_len);
        t_check_ints("dutch()", got, tt->in_len, tt->want, tt->want_len);
    }
    return t_done();
}
