import pytest

from misc.isprime import count_primes, get_primes, is_prime


@pytest.mark.parametrize(
    ("n", "want"),
    [(1, False), (2, True), (3, True), (4, False), (5, True), (167, True)],
)
def test_is_prime(n: int, want: bool) -> None:
    assert is_prime(n) == want


@pytest.mark.parametrize(
    ("n", "want"),
    [(1, 0), (10, 4), (100, 25), (1000, 168), (10000, 1229)],
)
def test_count_primes(n: int, want: int) -> None:
    assert count_primes(n) == want


@pytest.mark.parametrize(
    ("n", "want"),
    [
        (1, []),
        (10, [2, 3, 5, 7]),
        (20, [2, 3, 5, 7, 11, 13, 17, 19]),
        (30, [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]),
        (
            100,
            [
                2,
                3,
                5,
                7,
                11,
                13,
                17,
                19,
                23,
                29,
                31,
                37,
                41,
                43,
                47,
                53,
                59,
                61,
                67,
                71,
                73,
                79,
                83,
                89,
                97,
            ],
        ),
    ],
)
def test_get_primes(n: int, want: list[int]) -> None:
    assert get_primes(n) == want
