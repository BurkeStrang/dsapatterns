#include "kpairslargestsum.c"

#include "testing/testing.h"

int main(void)
{
    struct test
    {
        const char *name;
        const int *nums1;
        int nums1_len;
        const int *nums2;
        int nums2_len;
        int k;
        const char *want;
    } tests[] = {
        {"Example 1", INTS(9, 8, 2), INTS(6, 3, 1), 3,
         "[[9, 3], [8, 6], [9, 6]]"},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntMatrix got = find_k_largest_pairs(tt->nums1, tt->nums1_len,
                                             tt->nums2, tt->nums2_len, tt->k);
        t_check_matrix("find_k_largest_pairs()", &got, tt->want);
        intmatrix_free(&got);
    }
    return t_done();
}
