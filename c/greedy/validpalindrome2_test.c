#include "validpalindrome2.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *input;
        bool want;
    } tests[] = {
        {"Example 1", "racecar", true},
        {"Example 2", "abeccdeba", true},
        {"Example 3", "abcdef", false},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        bool got = is_palindrome_possible(tt->input);
        t_check_bool("is_palindrome_possible()", got, tt->want);
    }
    return t_done();
}
