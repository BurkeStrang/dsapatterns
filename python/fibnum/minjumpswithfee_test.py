import pytest

from fibnum.minjumpswithfee import find_min_fee


@pytest.mark.parametrize(
    ("fee", "want"),
    [
        pytest.param([1, 2, 5, 2, 1, 2], 3, id="Example 1"),
        pytest.param([2, 3, 4, 5], 5, id="Example 2"),
    ],
)
def test_find_min_fee(fee: list[int], want: int) -> None:
    assert find_min_fee(fee) == want
