#include "nextgreaterelement.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        int *nums1;
        int nums1_len;
        const int *nums2;
        int nums2_len;
        const int *want;
        int want_len;
    } tests[] = {
        {"Example 1", INTS(4, 2, 6), INTS(6, 2, 4, 5, 3, 7), INTS(5, 4, 7)},
        {"Example 2", INTS(9, 7, 1), INTS(1, 7, 9, 5, 4, 3), INTS(-1, 9, 7)},
        {"Example 3", INTS(5, 12, 3), INTS(12, 3, 5, 4, 10, 15),
         INTS(10, 15, 5)},
        {"No greater element", INTS(8), INTS(8, 7, 6), INTS(-1)},
        {"All increasing", INTS(1, 2, 3), INTS(1, 2, 3, 4), INTS(2, 3, 4)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int *got = next_greater_element(tt->nums1, tt->nums1_len, tt->nums2,
                                        tt->nums2_len);
        t_check_ints("next_greater_element()", got, tt->nums1_len, tt->want,
                     tt->want_len);
    }
    return t_done();
}
