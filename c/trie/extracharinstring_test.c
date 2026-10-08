#include "extracharinstring.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *s;
        const char *const *dictionary;
        int dictionary_len;
        int want;
    } tests[] = {
        {"Test Case 1", "amazingracecar", STRS("race"), 10},
        {"Test Case 2", "amazingracecar", STRS("race", "car"), 7},
        {"Test Case 3", "bookkeeperreading", STRS("keep", "read"), 9},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = min_extra_char(tt->s, tt->dictionary, tt->dictionary_len);
        t_check_int("min_extra_char()", got, tt->want);
    }
    return t_done();
}
