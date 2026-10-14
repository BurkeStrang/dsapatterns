import pytest

from knapsackdp.equalsumpartition import can_partition


@pytest.mark.parametrize(
    ("nums", "want"),
    [
        pytest.param([1, 2, 3, 4], True, id="Example 1"),
        pytest.param([1, 1, 3, 4, 7], True, id="Example 2"),
        pytest.param([2, 3, 4, 6], False, id="Example 3"),
    ],
)
def test_can_partition(nums: list[int], want: bool) -> None:
    assert can_partition(nums) == want
