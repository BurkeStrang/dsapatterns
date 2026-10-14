import pytest

from misc.fizzbuzz import fizz_buzz


@pytest.mark.parametrize(
    ("n", "want"),
    [
        pytest.param(5, ["1", "2", "Fizz", "4", "Buzz"], id="5"),
        pytest.param(
            15,
            [
                "1",
                "2",
                "Fizz",
                "4",
                "Buzz",
                "Fizz",
                "7",
                "8",
                "Fizz",
                "Buzz",
                "11",
                "Fizz",
                "13",
                "14",
                "FizzBuzz",
            ],
            id="15",
        ),
    ],
)
def test_fizz_buzz(n: int, want: list[str]) -> None:
    assert fizz_buzz(n) == want
