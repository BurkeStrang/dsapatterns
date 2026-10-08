#include "rearrangestring.c"

#include "testing/testing.h"

static bool same_letters
(
    const char *a,
    const char *b
)
{
    int counts[256] = {0};
    for (; *a != '\0'; a++)
    {
        counts[(unsigned char)*a]++;
    }
    for (; *b != '\0'; b++)
    {
        counts[(unsigned char)*b]--;
    }
    for (int i = 0; i < 256; i++)
    {
        if (counts[i] != 0)
        {
            return false;
        }
    }
    return true;
}

static bool has_equal_neighbours
(
    const char *s
)
{
    for (int i = 0; s[i] != '\0' && s[i + 1] != '\0'; i++)
    {
        if (s[i] == s[i + 1])
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    struct test
    {
        const char *name;
        const char *str;
        // whether the letters can be rearranged so that no two neighbours are
        // the same; when they cannot, an empty string is expected
        bool possible;
    } tests[] = {
        {"two letters", "aappp", true},
        {"many letters", "Programming", true},
        {"not possible", "aapa", false},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        char *got = rearrange_string(tt->str);
        if (got == NULL)
        {
            t_errorf("rearrange_string() = NULL");
        }
        else if (!tt->possible)
        {
            t_check_str("rearrange_string()", got, "");
        }
        else if (!same_letters(tt->str, got) || has_equal_neighbours(got))
        {
            t_errorf("rearrange_string() = \"%s\"", got);
        }
        free(got);
    }
    return t_done();
}
