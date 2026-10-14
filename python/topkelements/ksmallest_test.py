import pytest

from topkelements.ksmallest import find_kth_smallest_number


@pytest.mark.parametrize(
    ("nums", "k", "want"),
    [
        pytest.param([1, 5, 12, 2, 11, 5], 3, 5, id="Example 1"),
        pytest.param([1, 5, 12, 2, 11, 5], 4, 5, id="Example 2"),
        pytest.param([5, 12, 11, -1, 12], 3, 11, id="Example 3"),
        pytest.param([1, 5, 12, 2, 11, 5], 1, 1, id="Example 4"),
    ],
)
def test_find_kth_smallest_number(nums: list[int], k: int, want: int) -> None:
    assert find_kth_smallest_number(nums, k) == want
