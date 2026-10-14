import pytest

from knapsackdp.minsubsetsumdiff import can_partition_min


@pytest.mark.parametrize(
    ("num", "want"),
    [
        pytest.param([1, 2, 3, 9], 3, id="Example 1"),
        pytest.param([1, 2, 7, 1, 5], 0, id="Example 2"),
        pytest.param([1, 3, 100, 4], 92, id="Example 3"),
    ],
)
def test_can_partition_min(num: list[int], want: int) -> None:
    assert can_partition_min(num) == want
