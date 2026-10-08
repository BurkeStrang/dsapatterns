#include "common/list.h"

#include <stdbool.h>

bool is_prime
(
    int n
)
{
    // no number you can divide n by without leaving a remainder other than 1
    // and n itself
    if (n < 2)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n % 2 == 0)
    {
        return false;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int count_primes
(
    int n
)
{
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime(i))
        {
            count++;
        }
    }
    return count;
}

// The primes are returned in a list that the caller must free.
IntList get_primes
(
    int n
)
{
    IntList res = {0};
    for (int i = 2; i <= n; i++)
    {
        if (is_prime(i))
        {
            intlist_push(&res, i);
        }
    }
    return res;
}
