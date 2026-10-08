#include "fizzbuzz.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int n;
        const char *const *want;
        int want_len;
    } tests[] = {
        {"5", 5, STRS("1", "2", "Fizz", "4", "Buzz")},
        {"15", 15,
         STRS("1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz",
              "11", "Fizz", "13", "14", "FizzBuzz")},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        StrList got = fizz_buzz(tt->n);
        t_check_text("fizz_buzz()",
                     t_format_strs((const char *const *)got.items, got.len),
                     t_format_strs(tt->want, tt->want_len));
        strlist_free(&got);
    }
    return t_done();
}
