#include "isprime.c"

#include "testing/testing.h"

static void test_is_prime(void)
{
    struct test
    {
        const char *name;
        int n;
        bool want;
    } tests[] = {
        {"1", 1, false}, {"2", 2, true}, {"3", 3, true},
        {"4", 4, false}, {"5", 5, true}, {"167", 167, true},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        bool got = is_prime(tt->n);
        t_check_bool("is_prime()", got, tt->want);
    }
}

static void test_count_primes(void)
{
    struct test
    {
        const char *name;
        int n;
        int want;
    } tests[] = {
        {"1", 1, 0},         {"10", 10, 4},          {"100", 100, 25},
        {"1000", 1000, 168}, {"10000", 10000, 1229},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        int got = count_primes(tt->n);
        t_check_int("count_primes()", got, tt->want);
    }
}

static void test_get_primes(void)
{
    struct test
    {
        const char *name;
        int n;
        const int *want;
        int want_len;
    } tests[] = {
        {"1", 1, NO_INTS},
        {"10", 10, INTS(2, 3, 5, 7)},
        {"20", 20, INTS(2, 3, 5, 7, 11, 13, 17, 19)},
        {"30", 30, INTS(2, 3, 5, 7, 11, 13, 17, 19, 23, 29)},
        {"100", 100,
         INTS(2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
              61, 67, 71, 73, 79, 83, 89, 97)},
    };
    for (int i = 0; i < LEN(tests); i++)
    {
        const struct test *tt = &tests[i];
        t_run(tt->name);
        IntList got = get_primes(tt->n);
        t_check_ints("get_primes()", got.items, got.len, tt->want,
                     tt->want_len);
        intlist_free(&got);
    }
}

int main(void)
{
    test_is_prime();
    test_count_primes();
    test_get_primes();
    return t_done();
}
