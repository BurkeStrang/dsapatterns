import pytest

from slidingwindow.subscountlessthantarget import find_subarray_count


@pytest.mark.parametrize(
    ("nums", "target", "want"),
    [
        pytest.param([2, 5, 3, 10], 30, 6, id="Example 1"),
        pytest.param([8, 2, 6, 5], 50, 7, id="Example 2"),
        pytest.param([10, 5, 2, 6], 0, 0, id="Example 3 (target 0)"),
        pytest.param([1], 2, 1, id="Single element < target"),
        pytest.param([5], 5, 0, id="Single element >= target"),
    ],
)
def test_find_subarray_count(nums: list[int], target: int, want: int) -> None:
    assert find_subarray_count(nums, target) == want
