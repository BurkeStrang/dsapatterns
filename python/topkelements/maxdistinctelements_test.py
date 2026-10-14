import pytest

from topkelements.maxdistinctelements import find_maximum_distinct_elements


@pytest.mark.parametrize(
    ("nums", "k", "want"),
    [
        pytest.param([7, 3, 5, 8, 5, 3, 3], 2, 3, id="Example 1"),
        pytest.param([3, 5, 12, 11, 12], 3, 2, id="Example 2"),
        pytest.param([1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5], 2, 3, id="Example 3"),
    ],
)
def test_find_maximum_distinct_elements(
    nums: list[int], k: int, want: int
) -> None:
    assert find_maximum_distinct_elements(nums, k) == want
