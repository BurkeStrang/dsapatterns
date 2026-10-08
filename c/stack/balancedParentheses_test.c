#include "balancedParentheses.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *s1;
        bool want;
    } tests[] = {
        {"Example 1 - balanced", "{[()]}", true},
        {"Example 2 - not balanced", "{[}]", false},
        {"Example 3 - not balanced", "(]", false},
        {"Empty string - balanced", "", true},
        {"Single type - balanced", "()[]{}", true},
        {"Single type - not balanced", "(((", false},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        bool got = valid_parentheses(tt->s1);
        t_check_bool("valid_parentheses()", got, tt->want);
    }
    return t_done();
}
