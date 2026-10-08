#include "balanceparentheses.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int num;
        const char *const *want;
        int want_len;
    } tests[] = {
        {"example 1", 2, STRS("(())", "()()")},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        StrList got = generate_valid_parentheses(tt->num);
        t_check_text("generate_valid_parentheses()",
                     t_format_strs((const char *const *)got.items, got.len),
                     t_format_strs(tt->want, tt->want_len));
        strlist_free(&got);
    }
    return t_done();
}
