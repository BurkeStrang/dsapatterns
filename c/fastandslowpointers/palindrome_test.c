#include "palindrome.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *input;
        int input_len;
        bool expected;
    } tests[] = {
        {"case 1", INTS(2, 4, 6, 4, 2), true},
        {"case 2", INTS(2, 4, 6, 4, 2, 2), false},
        {"case 3", NO_INTS, true},
        {"case 4", INTS(1), true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        ListNode *nodes = list_from(tt->input, tt->input_len);
        bool got = is_palindrome(nodes);
        t_check_bool("is_palindrome()", got, tt->expected);
        free(nodes);
    }
    return t_done();
}
