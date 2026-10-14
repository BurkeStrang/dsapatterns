import pytest

from kwaymerge.smallestrange import find_smallest_range


@pytest.mark.parametrize(
    ("lists", "want"),
    [
        pytest.param([[1, 5, 8], [4, 12], [7, 8, 10]], [4, 7], id="Example 1"),
        pytest.param([[1, 9], [4, 12], [7, 10, 16]], [9, 12], id="Example 2"),
    ],
)
def test_find_smallest_range(lists: list[list[int]], want: list[int]) -> None:
    assert find_smallest_range(lists) == want
