"""
A prime is a number bigger than 1 that only 1 and the number itself divide
without a remainder.
"""


def is_prime(n: int) -> bool:
    # no number you can divide n by without leaving a remainder other than 1
    # and n itself
    if n < 2:
        return False
    if n in (2, 3):
        return True
    if n % 2 == 0:
        return False

    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2

    return True


def count_primes(n: int) -> int:
    count = 0
    for i in range(2, n + 1):
        if is_prime(i):
            count += 1
    return count


def get_primes(n: int) -> list[int]:
    return [i for i in range(2, n + 1) if is_prime(i)]
