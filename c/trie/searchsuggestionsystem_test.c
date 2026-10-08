#include "searchsuggestionsystem.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const char *const *products;
        int products_len;
        const char *search_word;
        // the expected suggestions for each letter typed, joined with spaces
        const char *const *want;
        int want_len;
    } tests[] = {
        {"Test Case 1",
         STRS("mobile", "mouse", "moneypot", "monitor", "mousepad"), "mouse",
         STRS("mobile moneypot monitor", "mobile moneypot monitor",
              "mouse mousepad", "mouse mousepad", "mouse mousepad")},
        {"Test Case 2", STRS("havana"), "havana",
         STRS("havana", "havana", "havana", "havana", "havana", "havana")},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        StrList *got =
            suggested_products(tt->products, tt->products_len, tt->search_word);
        for (int n = 0; n < tt->want_len; n++)
        {
            if (got == NULL)
            {
                t_errorf("suggested_products() = NULL");
                break;
            }
            char *joined = t_format_buffer();
            for (int s = 0; s < got[n].len; s++)
            {
                t_format_append(joined, s == 0 ? "" : " ");
                t_format_append(joined, got[n].items[s]);
            }
            t_check_str("suggestions", joined, tt->want[n]);
            strlist_free(&got[n]);
        }
        free(got);
    }
    return t_done();
}
