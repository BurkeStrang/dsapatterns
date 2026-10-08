#include "reverseString.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *input;
        const char *want;
    } tests[] = {
        {"Example 1", "Hello, World!", "!dlroW ,olleH"},
        {"Example 2", "OpenAI", "IAnepO"},
        {"Example 3", "Stacks are fun!", "!nuf era skcatS"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char *got = reverse_string(tt->input);
        t_check_str("reverse_string()", got, tt->want);
        free(got);
    }
    return t_done();
}
