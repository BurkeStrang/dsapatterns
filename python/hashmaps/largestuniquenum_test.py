import pytest

from hashmaps.largestuniquenum import largest_unique_number


@pytest.mark.parametrize(
    ("a", "want"),
    [
        pytest.param([5, 7, 3, 7, 5, 8], 8, id="Example 1"),
        pytest.param([1, 2, 3, 2, 1, 4, 4], 3, id="Example 2"),
        pytest.param([9, 9, 8, 8, 7, 7], -1, id="Example 3"),
    ],
)
def test_largest_unique_number(a: list[int], want: int) -> None:
    assert largest_unique_number(a) == want
