import pytest

from monotonicstack.sumofsumarraymin import sum_subarray_mins


@pytest.mark.parametrize(
    ("arr", "want"),
    [
        pytest.param([3, 1, 2, 4, 5], 30, id="Example 1"),
        pytest.param([2, 6, 5, 4], 36, id="Example 2"),
        pytest.param([7, 3, 8], 27, id="Example 3"),
        pytest.param([5], 5, id="Single element"),
        pytest.param([2, 2, 2], 12, id="All same elements"),
    ],
)
def test_sum_subarray_mins(arr: list[int], want: int) -> None:
    assert sum_subarray_mins(arr) == want
