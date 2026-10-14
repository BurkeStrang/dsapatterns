import pytest

from knapsackdp.countofsubsetsum import count_subsets


@pytest.mark.parametrize(
    ("num", "target", "want"),
    [
        pytest.param([1, 1, 2, 3], 4, 3, id="Example 1"),
        pytest.param([1, 2, 7, 1, 5], 9, 3, id="Example 2"),
    ],
)
def test_count_subsets(num: list[int], target: int, want: int) -> None:
    assert count_subsets(num, target) == want
