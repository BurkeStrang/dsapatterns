import pytest

from knapsackdp.subsetsum import can_partition_sum


@pytest.mark.parametrize(
    ("nums", "target", "want"),
    [
        pytest.param([1, 2, 3, 7], 6, True, id="Example 1"),
        pytest.param([1, 2, 7, 1, 5], 10, True, id="Example 2"),
        pytest.param([1, 3, 4, 8], 6, False, id="Example 3"),
    ],
)
def test_can_partition_sum(nums: list[int], target: int, want: bool) -> None:
    assert can_partition_sum(nums, target) == want
