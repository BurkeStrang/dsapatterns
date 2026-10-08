#include "nextletter.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *letters;
        int letters_len;
        char key;
        char want;
    } tests[] = {
        {"key in middle of array", CHARS('a', 'c', 'f', 'h'), 'f', 'h'},
        {"key before first element", CHARS('a', 'c', 'f', 'h'), 'b', 'c'},
        {"key is smallest element", CHARS('a', 'c', 'f', 'h'), 'a', 'c'},
        {"key is largest element - wraps around", CHARS('a', 'c', 'f', 'h'),
         'h', 'a'},
        {"key larger than all - wraps around", CHARS('a', 'c', 'f', 'h'), 'z',
         'a'},
        {"key smaller than all elements", CHARS('c', 'f', 'j'), 'a', 'c'},
        {"key between two adjacent elements", CHARS('a', 'c', 'f', 'h'), 'g',
         'h'},
        {"single element - wraps around", CHARS('m'), 'm', 'm'},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char got = search_next_letter(tt->letters, tt->letters_len, tt->key);
        t_check_char("search_next_letter()", got, tt->want);
    }
    return t_done();
}
