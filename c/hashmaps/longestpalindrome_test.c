#include "longestpalindrome.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *s;
        int want;
    } tests[] = {
        {"applepie", "applepie", 5}, {"aabbcc", "aabbcc", 6},
        {"bananas", "bananas", 5},   {"single character", "a", 1},
        {"all unique", "abcdef", 1}, {"all pairs", "aabb", 4},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = longest_palindrome(tt->s);
        t_check_int("longest_palindrome()", got, tt->want);
    }
    return t_done();
}
