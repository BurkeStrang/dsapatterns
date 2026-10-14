import pytest

from knapsackdp.targetsum import find_target_subsets


@pytest.mark.parametrize(
    ("num", "s", "want"),
    [
        pytest.param([1, 1, 2, 3], 1, 3, id="Example 1"),
        pytest.param([1, 2, 7, 1], 9, 2, id="Example 2"),
    ],
)
def test_find_target_subsets(num: list[int], s: int, want: int) -> None:
    assert find_target_subsets(num, s) == want
